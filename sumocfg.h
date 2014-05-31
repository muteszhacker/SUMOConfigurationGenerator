//---------------------------------SUMOCFG file---------------------------------
unsigned int		uiBegin		=	0;
unsigned int		uiEnd		=	0;
//------------------------------------------------------------------------------
// Trich ten file tu duong dan day du
void Trim_file_name(char *filename, string &temp);
// In file sumocfg
void Print_sumocfg_file();
//------------------------------------------------------------------------------

// Trich ten file tu duong dan day du
void Trim_file_name(char *filename, string &temp)	{
    temp.clear();
    
    for (int i=strlen(filename)-1; i>=0; --i)	{
    	if (filename[i]=='\\')
    		break;
    	temp.insert(temp.begin(), filename[i]);
    }	
}

// In file sumocfg
void Print_sumocfg_file()   {
    fstream fout(agrsb[5].szFileName, ios::out);

    fout << "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>" << endl
    	 << "<configuration xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-"
		 << "instance\" xsi:noNamespaceSchemaLocation=\""
		 << "http://sumo.sf.net/xsd/sumoConfiguration.xsd\">" << endl
    	 << "<input>" << endl;
    
    string temp;
    Trim_file_name(agrsb[2].szFileName, temp);
    fout << "<net-file value=\"" << temp << "\"/>" << endl;
    Trim_file_name(agrsb[4].szFileName, temp);
    fout << "<route-files value=\"" << temp << "\"/>" << endl;
    
    fout << "</input>" << endl
    	 << "<time>" << endl
    	 << "<begin value=\"" << uiBegin << "\"/>" << endl
    	 << "<end value=\"" << uiEnd << "\"/>" << endl
    	 << "</time>" << endl
    	 << "</configuration>";

    fout.close();
}
//------------------------------------------------------------------------------
