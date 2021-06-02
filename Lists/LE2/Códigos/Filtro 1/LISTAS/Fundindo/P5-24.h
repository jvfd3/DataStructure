/*	==================== cmpYear ====================	Compares two years in PICTURE structures	   Pre  year1 is a pointer to the first structure	        year2 is a pointer to the second structure	   Post two years compared and result returned	Return -1 if year1 less; 0 if equal; +1 greater*/int cmpYear (void* pYear1, void* pYear2){//	Local Definitions 	int   result;	short year1;	short year2;//	Statements 	year1 = ((PICTURE*)pYear1)->year;	year2 = ((PICTURE*)pYear2)->year;	if (year1 < year2)	    result = -1;	else if (year1 > year2)	    result = +1;	else	    result = 0;	return result;}	// cmpYear 