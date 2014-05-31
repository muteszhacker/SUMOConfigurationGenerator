//---------------------------------TYPXML file----------------------------------
// Loai duong
struct	Edge_type	{
	string		strId;
	bool		bOneway;
	int			iPriority;
	int			iNumLanes;
	float		fSpeed;
	char		szAllow[13];
	char		szDisallow[13];
};
//------------------------------------------------------------------------------
vector <Edge_type>	etypList;
//------------------------------------------------------------------------------
// Thiet lap thong tin loai duong
void Set_edge_att(Edge_type &etyp, string id, bool oneway, int priority, 
		int numLanes, float speed, char allow[13], char disallow[13]);
// Thiet lap gia tri mac dinh cho edge type
void Default_typ();
// In phuong tien duoc phep / khong duoc phep
void Print_aldis_items(fstream &fout, char aldis[13]);
// In file typ
void Print_typ_file();
//------------------------------------------------------------------------------

// Thiet lap thong tin loai duong
void Set_edge_att(Edge_type &etyp, string id, bool oneway, int priority, 
		int numLanes, float speed, char allow[13], char disallow[13])	{
	etyp.strId		=	id;
	etyp.bOneway	=	oneway;
	etyp.iPriority	=	priority;
	etyp.iNumLanes	=	numLanes;
	etyp.fSpeed		=	speed;
	
	for (int i=0; i<13; ++i)	{
		etyp.szAllow[i] = allow[i];
		etyp.szDisallow[i] = disallow[i];
	}
}

// Thiet lap gia tri mac dinh cho edge type
void Default_typ()	{
	etypList.resize(30);
	
	Set_edge_att(etypList[0], aszItems_TYP_id[0], true, 13, 4, 41.667, 
		"0000000000000", "000000110000");
	Set_edge_att(etypList[1], aszItems_TYP_id[1], false, 8, 4, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[2], aszItems_TYP_id[2], false, 12, 2, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[3], aszItems_TYP_id[3], false, 8, 2, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[4], aszItems_TYP_id[4], false, 11, 5, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[5], aszItems_TYP_id[5], false, 8, 5, 13.889, 
		"0000000000000", "000000000000");
	Set_edge_att(etypList[6], aszItems_TYP_id[6], false, 10, 4, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[7], aszItems_TYP_id[7], false, 8, 4, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[8], aszItems_TYP_id[8], false, 9, 3, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[9], aszItems_TYP_id[9], false, 8, 2, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[10], aszItems_TYP_id[10], false, 7, 2, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[11], aszItems_TYP_id[11], false, 7, 2, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[12], aszItems_TYP_id[12], false, 6, 2, 1.389, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[13], aszItems_TYP_id[13], false, 5, 1, 1.389, 
		"000000010000", "000000000000");
	Set_edge_att(etypList[14], aszItems_TYP_id[14], false, 5, 1, 13.889, 
		"000000000000", "000000000000");
	Set_edge_att(etypList[15], aszItems_TYP_id[15], false, 5, 1, 13.889, 
		"010000000000", "000000000000");
	Set_edge_att(etypList[16], aszItems_TYP_id[16], false, 4, 1, 8.333, 
		"000000110000", "000000000000");
	Set_edge_att(etypList[17], aszItems_TYP_id[17], false, 2, 1, 6.944, 
		"000000110000", "000000000000");
	Set_edge_att(etypList[18], aszItems_TYP_id[18], false, 2, 1, 6.944, 
		"000000100000", "000000000000");
	Set_edge_att(etypList[19], aszItems_TYP_id[19], false, 2, 1, 1.389, 
		"000000010000", "000000000000");
	Set_edge_att(etypList[20], aszItems_TYP_id[20], false, 2, 1, 6.944, 
		"000000110000", "000000000000");
	Set_edge_att(etypList[21], aszItems_TYP_id[21], false, 2, 1, 1.389, 
		"000000010000", "000000000000");
	Set_edge_att(etypList[22], aszItems_TYP_id[22], false, 7, 1, 22.222, 
		"000000000001", "000000000000");
	Set_edge_att(etypList[23], aszItems_TYP_id[23], false, 7, 1, 16.667, 
		"000000000100", "000000000000");
	Set_edge_att(etypList[24], aszItems_TYP_id[24], false, 7, 1, 33.333, 
		"000000001000", "000000000000");
	Set_edge_att(etypList[25], aszItems_TYP_id[25], false, 7, 1, 22.222, 
		"000000000100", "000000000000");
	Set_edge_att(etypList[26], aszItems_TYP_id[26], false, 7, 1, 8.333, 
		"000000001000", "000000000000");
	Set_edge_att(etypList[27], aszItems_TYP_id[27], false, 7, 1, 33.333, 
		"000000001000", "000000000000");
	Set_edge_att(etypList[28], aszItems_TYP_id[28], false, 7, 1, 16.667, 
		"000000001000", "00000000000");
	Set_edge_att(etypList[29], aszItems_TYP_id[29], false, 7, 1, 16.667, 
		"000000000100", "000000000000");
}

// In phuong tien duoc phep / khong duoc phep
void Print_aldis_items(fstream &fout, char aldis[13])	{
	for (int j=0; j<12; ++j)	{
		if (aldis[j]=='1')	{
 		 	fout << " allow=\"" << agrcCheck_TYP[j].szLabel;
 			 	
 		 	for (int k=j+1; k<12; ++k)
 		 		if (aldis[k]=='1')
	 		 		fout << " " << agrcCheck_TYP[k].szLabel;
			 		
	 		fout << "\"";
	 		break;
	 	}
 	}
}

// In file typ
void Print_typ_file()	{
    fstream fout(agrsb[1].szFileName, ios::out);
	
	fout << "<types xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
		 << "xsi:noNamespaceSchemaLocation="
		 << "\"http://sumo.sf.net/xsd/types_file.xsd\">" << endl;
	
	for (int i=0; i<etypList.size(); ++i)	{
		fout << "<type"
			 << " id=\"" << etypList[i].strId << "\"";
	 	
	 	if (etypList[i].bOneway)
	 		fout << " oneway=\"true\"";
 		
 		fout << " priority=\"" << etypList[i].iPriority << "\""
			 << " numLanes=\"" << etypList[i].iNumLanes << "\""
			 << " speed=\""    << etypList[i].fSpeed    << "\"";
	 	
	 	Print_aldis_items(fout, etypList[i].szAllow);
	 	Print_aldis_items(fout, etypList[i].szDisallow);
	 	
		fout << "/>" << endl;
	}
	
	fout << "</types>" << endl;
}
//------------------------------------------------------------------------------
