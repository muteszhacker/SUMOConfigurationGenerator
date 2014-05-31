//--------------------------------ROUXML file-----------------------------------
struct Color	{
	float red, green, blue;
};

struct Veh_Info	{
	int id;
	string type;
	int trip;
	Color color;
	int depart;
};
//------------------------------------------------------------------------------
unsigned int		uiVehicles	=	0;
unsigned int		uiTrips		=	0;
//------------------------------------------------------------------------------
// In cac thuoc tinh
void Print_att(fstream &fout, string s, string att, int &j);
// In thong tin phuong tien
void Print_veh_type(fstream &fout, vector <string> veh_type);
// Cap nhat diem dau
int Update_start(vector <Route> &list, int i, int next);
// In 1 lo trinh
void Print_trip(fstream &fout, vector <string> trip, int j);
// Tao hanh trinh ngau nhien
void Print_random_trips(fstream &fout, vector <Route> &list);
// Sinh phuong tien ngau nhien
void Print_random_veh(fstream &fout, vector <string> veh_type, 
		vector <string> veh_id);
// In file .rou.xml
void Print_rou_file(vector <Route> &list);
//------------------------------------------------------------------------------

// In cac thuoc tinh
void Print_att(fstream &fout, string s, string att, int &j)    {
    fout << " " << att << "=\"";

    ++j;
    while (s[j]!=' ' && j<s.size())
        fout << s[j++];

    fout << "\"";
}

// In thong tin phuong tien
void Print_veh_type(fstream &fout, vector <string> veh_type)    {
	fout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl << endl
		 << "<routes xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\""
		 << " xsi:noNamespaceSchemaLocation="
		 << "\"http://sumo.sf.net/xsd/routes_file.xsd\">" << endl;

	for (int i=0; i<veh_type.size(); ++i)    {
	    int j=-1;

        fout << "<vType";
        for (int k=3; k<13; ++k)
        	Print_att(fout, veh_type[i], agrsc_edit[k].szStatic, j);
        fout << "/>" << endl;
	}

	fout << endl;
}

// Cap nhat diem dau
int Update_start(vector <Route> &list, int i, int next)	{
	int k=0;
	
	while (k<list.size() && list[k].strFrom != list[i].avAvail[next].strTo)
		++k;
	
	return k;
}

// In 1 lo trinh
void Print_trip(fstream &fout, vector <string> trip, int j)	{
	fout << "<route id=\"route" << j << "\" edges=\"";
	
	for (int i=0; i<trip.size(); ++i)
		fout << trip[i] << " ";
		
	fout << "\"/>" << endl;
}

// Tao hanh trinh ngau nhien voi dieu kien:
//- Tong so lo trinh xac dinh = vehicles
//- Khong cho phep re chu U
//- Ket thuc tai mot nut bat ky
void Print_random_trips(fstream &fout, vector <Route> &list)  {
    srand((unsigned)time(NULL));

    for (int j=0; j<uiTrips; ++j) {
        vector <string> trip;               // Lo trinh
        vector <string> nodes_list;         // Danh sach cac nut trong lo trinh

        // Diem xuat phat ngau nhien
        int i = rand() % list.size();
        nodes_list.push_back(list[i].strFrom);

		// Diem thu 2
		int next = rand() % list[i].avAvail.size();
        nodes_list.push_back(list[i].avAvail[next].strTo);
        trip.push_back(list[i].avAvail[next].strId);
		i = Update_start(list, i, next);

		// Xay dung cac nut tiep theo cua lo trinh
        int counter = 1, length = rand() % uiNodes + 1;
				        
        while (counter<length && list[i].avAvail.size()>1)	{
        	// Tim nut tiep theo sao cho khong tao U Turn
			do	
				next = rand() % list[i].avAvail.size();
    		while(list[i].avAvail[next].strTo==nodes_list[nodes_list.size()-2]);
        	
            // Luu lo trinh
            nodes_list.push_back(list[i].avAvail[next].strTo);
            trip.push_back(list[i].avAvail[next].strId);
			i = Update_start(list, i, next);
            
            ++counter;
        } 

		Print_trip(fout, trip, j);
    }
    
    fout << endl;
}

// Sinh phuong ten ngau nhien thoa man ti le loai phuong tien cho truoc
void Print_random_veh(fstream &fout, vector <string> veh_type, 
		vector <Veh_ID> veh_id) {
	vector <Veh_Info>	veh_info;
	int counter = 0;
	
	srand((unsigned)time(NULL));

	// Tao ngau nhien theo loai phuong tien truoc (23 loai)
	for (int i=0; i<23; ++i)	{
		int vehs = (int) (rate[i]*uiVehicles);
		
		for (int j=0; j<vehs; ++j)	{
			Veh_Info temp_vif;
			
			temp_vif.id = counter;
			temp_vif.type = temp_vif.type + char(aszItems_VIN_guiShape[i][0]-32) 
				+ aszItems_VIN_guiShape[i][1] + aszItems_VIN_guiShape[i][2];

			temp_vif.trip = rand()%uiTrips;
			temp_vif.color.red = float(rand()) / RAND_MAX;
			temp_vif.color.green = float(rand()) / RAND_MAX;
			temp_vif.color.blue = float(rand()) / RAND_MAX;
			temp_vif.depart = rand() % 20000;
						
			veh_info.push_back(temp_vif);
			++counter;
		}
	}	

	// Sap xep lai thu tu cac phuong tien in ra theo gia tri depart tang dan
	// su dung Buble Sort -> phai cai tien
	for (int i=0; i<counter-1; ++i)
		for (int j=i+1; j<counter; ++j)
			if (veh_info[i].depart > veh_info[j].depart)	{
				Veh_Info temp_vif;
				
				temp_vif.id = veh_info[i].id;
				temp_vif.type = veh_info[i].type;
				temp_vif.trip = veh_info[i].trip;
				temp_vif.color.red = veh_info[i].color.red;
				temp_vif.color.green = veh_info[i].color.green;
				temp_vif.color.blue = veh_info[i].color.blue;
				temp_vif.depart = veh_info[i].depart;
				
				veh_info[i].id = veh_info[j].id;
				veh_info[i].type = veh_info[j].type;
				veh_info[i].trip = veh_info[j].trip;
				veh_info[i].color.red = veh_info[i].color.red;
				veh_info[i].color.green = veh_info[j].color.green;
				veh_info[i].color.blue = veh_info[j].color.blue;
				veh_info[i].depart = veh_info[j].depart;

				veh_info[j].id = temp_vif.id;
				veh_info[j].type = temp_vif.type;
				veh_info[j].trip = temp_vif.trip;
				veh_info[j].color.red = temp_vif.color.red;
				veh_info[j].color.green = temp_vif.color.green;
				veh_info[j].color.blue = temp_vif.color.blue;
				veh_info[j].depart = temp_vif.depart;	
			}
	
    // In thong tin cac phuong tien file
	for (int i=0; i<counter; ++i)   {
        fout << "<vehicle "
             << "id=\"veh"      << veh_info[i].id << "\" "
             << "type=\""       << veh_info[i].type << rand()%(vins/5) << "\" "
             << "route=\"route" << veh_info[i].trip << "\" "
             << "color=\""      << veh_info[i].color.red << "," 
			 					<< veh_info[i].color.green << "," 
							 	<< veh_info[i].color.blue << "\" "
             << "depart=\""     << veh_info[i].depart << "\" "
             << "/>" << endl;
    }
    fout << "</routes>" << endl;
}

// In file .rou.xml
void Print_rou_file(vector <Route> &list)   {
    vector <string> veh_type;
    vector <Veh_ID> veh_id;
    fstream fout(agrsb[4].szFileName, ios::out);

    Read_vin_file(veh_type, veh_id);
    Print_veh_type(fout, veh_type);
    Print_random_trips(fout, rouList);
    Print_random_veh(fout, veh_type, veh_id);

    fout.close();
}
//------------------------------------------------------------------------------
