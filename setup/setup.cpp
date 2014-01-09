/*****************************************************************************
 *                                                                           *
 * setup.c                                                                   *
 * Created 26/12/13                                                          *
 *                                                                           *
 * Copyright 2013 Tony Orme                                                  *
 *                                                                           *
 * Email - tonyorme111@gmail.com                                             *
 *                                                                           *
 * This file is part of FileAccelerator                                      *
 *                                                                           *
 * FileAccelerator is free software: you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation, either version 3 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * FileAccelerator is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License for more details.                              *
 *                                                                           *
 * You should have received a copy of the GNU General Public License         *
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.           *
 *                                                                           *
 *                                                                           *
 ****************************************************************************/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include "setup.h"

using namespace std;

SETUP::SETUP(const char* FileName){

  string tmpStr(FileName);
  mFileName=tmpStr;
  cout << "Filename is " << mFileName << endl;
}


int SETUP::mInitialise(void){

  int RetVal= -1;
  int line_count=0;

  try{
    char buffer[256];

    ifstream myfile (mFileName.c_str());

    if(myfile.is_open()){

      cout << "Opening file -> " << mFileName << ",";
      while (! myfile.eof()){
	myfile.getline (buffer,256);
	if((buffer[0]!='#')&&(buffer[0]!='\0')){
	  switch(line_count++){ 
	  case 0:
	    mSetFileVersion(buffer);
	    cout << " version -> " << mGetFileVersion()->c_str() << endl;
	    break;
	  case 1:
	    mSetDate(buffer);
	    break;
	  case 2:
	    mSetSrcIpAddress(buffer);
	    break;
	  case 3:
	    mSetSrcPortAddress(buffer);
	    break;
	  case 4:
	    mSetDstIpAddress(buffer);
	    break;
	  case 5:
	    mSetDstPortAddress(buffer);
	    break;
	  }
	}
      }
      myfile.close();
    }
    else{
      cout << "Cannot open file " << endl;
      RetVal=0;
    }
  }catch(...){
    cout << "There was an error trying to open file -> " << mFileName << endl;
    RetVal = 0;
  }
  return RetVal;
}


string* SETUP::mGetFileName(void){
   return &mFileName;
}

string* SETUP::mGetFileVersion(void){
  return &strFileVersion;
}


SETUP::~SETUP(void){
}
