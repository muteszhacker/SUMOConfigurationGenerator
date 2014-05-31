//-----------------------------------VIN file-----------------------------------
// Loai phuong tien
struct	Vin_type	{
	string strId;
	float accel;
	float decel;
	float length;
	float width;
	float minGap;
	float maxSpeed;
	float sigma;
	float tau;
	string strGuiShape;
};

struct Veh_ID	{
	string Type;
	int guiShape;
};
//------------------------------------------------------------------------------
vector <Vin_type>	vtypList;
unsigned int vins = 100;
vector <float> rate;
vector <int> type_amount;
//------------------------------------------------------------------------------
// Doc thong tin cac phuong tien tu file
void Read_vin_file(vector <string> &veh_type, vector <Veh_ID> &veh_id);
// Luu file vin
void Save_vin_file();
// Thiet lap thong tin loai duong
void Set_vin_att(vector <Vin_type> &list, string id, float accel, float decel, 
		float length, float width, float minGap, float maxSpeed, float sigma, 
		float tau, string guiShape);
// Thiet lap gia tri mac dinh cho vin
void Default_vin();
//------------------------------------------------------------------------------

// Doc thong tin cac phuong tien tu file
void Read_vin_file(vector <string> &veh_type, vector <Veh_ID> &veh_id) {
    fstream fin(agrsb[3].szFileName, ios::in);
    string strLine;

	rate.resize(23);
	type_amount.resize(23);

	// Doc phan dau tien la ti le cac loai phuong tien	
	while (!fin.eof())	{
		getline(fin, strLine);
		if (strLine == "")
			break;
		
		char temp_type[21];
		float temp_rate;
		
		sscanf(strLine.c_str(), "%s %f", temp_type, &temp_rate);
		
		for (int i=0; i<23; ++i)
			if (temp_type == (string)aszItems_VIN_guiShape[i])	{
				rate[i] = temp_rate;
				break;
			}
	}
	
	// Doc phan thu 2 la thong tin cac loai phuong tien cu the, 
	// moi loai xe co mot so loai khac nhau		
    while (!fin.eof())	{
        getline(fin, strLine);

        int j=0;
        Veh_ID temp_vid;

		// Luu loai xe nam o cuoi xau strLine        
        while (strLine[j] != ' ')
            temp_vid.Type = temp_vid.Type + strLine[j++];
        
        j = 0;        
        for (j=strLine.length()-1; j>=0; --j)
        	if (strLine[j]==' ')
        		break;
		
		// Loai xe chua trong bien temp_str
        string temp_str;        
		for (int i=j+1; i<strLine.length(); ++i)
			temp_str = temp_str + strLine[i];
		
		// Dua vao xau chua id loai xe, luu thong tin vao truong guiShape,
		// dong thoi tang so luong loai xe cua loai phuong tien tuong ung
		for (int i=0; i<23; ++i)
			if (temp_str == (string)aszItems_VIN_guiShape[i])	{
				temp_vid.guiShape = i;
				++type_amount[i];
				break;
			}
				
        veh_id.push_back(temp_vid);
        veh_type.push_back(strLine);
    }

    veh_type.pop_back();
}

// Luu file vin
void Save_vin_file()	{
	fstream fout(agrsb[3].szFileName, ios::out);
	
	for (int i=0; i<rate.size(); ++i)	
		if (rate[i]>0.0)
			fout << aszItems_VIN_guiShape[i] << " " << rate[i] << endl;
	fout << endl;
	
	for (int i=0; i<vtypList.size(); ++i)
		fout << vtypList[i].strId << " " << vtypList[i].accel << " " 
			 << vtypList[i].decel << " " << vtypList[i].length << " "
			 << vtypList[i].width << " " << vtypList[i].minGap << " "
			 << vtypList[i].maxSpeed << " " << vtypList[i].sigma << " "
			 << vtypList[i].tau << " " << vtypList[i].strGuiShape << endl;
	 
	fout.close();
}

// Thiet lap thong tin loai duong
void Set_vin_att(vector <Vin_type> &list, string id, float accel, float decel, 
		float length, float width, float minGap, float maxSpeed, float sigma, 
		float tau, string guiShape)		{
	Vin_type vtypTemp;
	
	vtypTemp.strId			=	id;
	vtypTemp.accel			=	accel;
	vtypTemp.decel			=	decel;
	vtypTemp.length			=	length;
	vtypTemp.width			=	width;
	vtypTemp.minGap			=	minGap;
	vtypTemp.maxSpeed		=	maxSpeed;
	vtypTemp.sigma			=	sigma;
	vtypTemp.tau			=	tau;
	vtypTemp.strGuiShape	=	guiShape;
	
	list.push_back(vtypTemp);
}

// Thiet lap rate mac dinh
void Default_rate()	{
	rate.resize(23);
	
	rate[1] = 0.1;
	rate[2] = 0.7;
	rate[3] = 0.14;
	rate[9] = 0.04;
	rate[12] = 0.02;
}

// Thiet lap gia tri mac dinh cho vin
void Default_vin()	{
	vtypList.clear();

	Set_vin_att(vtypList, "Tra0", 1.5, 4.0, 5.0, 1.75, 2.5, 30.0, 0.5, 1.0, 
		"transport");
	Set_vin_att(vtypList, "Bus0", 2.0, 5.0, 5.8, 2.2, 2.5, 30.0, 0.5, 1.0, 
		"bus");
	Set_vin_att(vtypList, "Pas0", 2.5, 6.0, 5.0, 2.0, 2.5, 40.0, 0.5, 1.0, 
		"passenger");
	Set_vin_att(vtypList, "Mot0", 3.0, 6.5, 2.5, 0.5, 0.5, 40.0, 0.5, 1.0, 
		"motorcycle");
	Set_vin_att(vtypList, "Bic0", 0.5, 1.0, 2.0, 0.3, 1.0, 4.0, 0.5, 1.0, 
		"bicycle");
	Default_rate();
}

// Them loai phuong tien ngau nhien
void Add_random_vin(string type, float accel, float decel, float length, 
		float width, float minGap, float maxSpeed, string guiShape)	{
    srand((unsigned)time(NULL));
    
	for (int i=0; i<vins/5; ++i)	{
		string strId = type;
		char *num = new char[5];
		
		itoa(i, num, 10);		
		strId = strId + num;
		
		float accel_new = accel*(0.5 + (float)rand()/RAND_MAX);
		float decel_new = decel*(0.5 + (float)rand()/RAND_MAX);
		float length_new = length*(1.0 + (float)rand()/RAND_MAX/5);
		float width_new = width*(1.0 + (float)rand()/RAND_MAX/5);
		float minGap_new = minGap*(0.5 + (float)rand()/RAND_MAX);
		float maxSpeed_new = maxSpeed*(0.5 + (float)rand()/RAND_MAX);
		float sigma_new = 0.5 + (float)rand()/RAND_MAX/2;
		float tau_new = 0.8 + (float)rand()/RAND_MAX/2;
		
		Set_vin_att(vtypList, strId, accel_new, decel_new, length_new, 
			width_new, minGap_new, maxSpeed_new, sigma_new, tau_new, guiShape);		
	}
}
//------------------------------------------------------------------------------
