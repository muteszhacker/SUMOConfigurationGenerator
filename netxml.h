//---------------------------------NETXML file----------------------------------
// Huong di co the
struct	Available    {
    string		strId;
    string		strTo;
};

// Cac tuyen duong
struct	Route    	{
    string				strFrom;
    vector <Available>	avAvail;
};
//------------------------------------------------------------------------------
unsigned int	uiNodes		=	0;
vector <Route>	rouList;
//------------------------------------------------------------------------------
// Netconverter tao file .net.xml
void NetConverter();
// Doc thuoc tinh tuyen duong
void Read_att(string line, string &att, int &i);
// Doc file net
void Read_net_file(vector <Route> &list);
//------------------------------------------------------------------------------

// Netconverter tao file .net.cml
void NetConverter()	{
	string strcommand = "netconvert";

	strcommand	= strcommand 
				+ " --osm-files \"" + agrsb[0].szFileName + "\""
 				+ " --type-files \"" + agrsb[1].szFileName + "\""
			  	+ " --output-file \"" + agrsb[2].szFileName + "\""
			  	+ " --geometry.remove --remove-edges.isolated --tls.join"
				+ " --ramps.guess --verbose --remove-edges.by-vclass "
 				+ "hov,taxi,bus,delivery,transport,lightrail,cityrail,"
				+ "rail_slow,rail_fast,motorcycle,bicycle,pedestrian";
	fstream f("a.log", ios::out);
	f << strcommand;
	f.close();
	system(strcommand.c_str());
}

// Doc thuoc tinh tuyen duong
void Read_att(string line, string &att, int &i)	{
	while (line[++i] != '\"')
		;
	while (line[++i] != '\"')
		att = att + line[i];
}

// Doc file net
void Read_net_file(vector <Route> &list)    {
    fstream fin(agrsb[2].szFileName, ios::in);
    string strLine;
	list.clear();
	
	// Bo qua phan chu thich
	while (!fin.eof())	{
		getline(fin, strLine);
		if (strLine == "-->")
			break;
	}
	
	// Bo qua phan edge internal
	for (int i=0; i<5; ++i)
		getline(fin, strLine);
	
	while (!fin.eof())	{
		getline(fin, strLine);
		if (strLine == "")
			break;
	}

	// Bat dau doc cac tuyen duong
	
    while (!fin.eof())    {			
        getline(fin, strLine);
		if (strLine[0]=='\0')
			break;
        
        // Doc id
        int i=-1;
        string strFrom;
        Available avTemp;

		Read_att(strLine, avTemp.strId, i);
		Read_att(strLine, strFrom, i);
		Read_att(strLine, avTemp.strTo, i);

        // Kiem tra diem dau da co chua, neu chua co thi them moi
        int j = 0;
        while (j<list.size() && list[j].strFrom != strFrom)
            ++j;

        if (j==list.size()) {
            Route rouTemp;
            rouTemp.strFrom = strFrom;
            list.push_back(rouTemp);
        }

        list[j].avAvail.push_back(avTemp);

        // Bo qua cac the lane va the dong edge
        while(1)  {
            getline(fin, strLine);
	        
            int i=0;
            while (strLine[i]==' ')
                ++i;

            if (i<strLine.size()-1 && strLine[i]=='<' && strLine[i+1]=='/')
                break;
        }
    }

    list.pop_back();
	fin.close();
    uiNodes = list.size();
}
//------------------------------------------------------------------------------
