/*****************************************************************************
 *                                                                           *
 * main.cpp                                                                  *
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
#include <string>
#include "setup/setup.h"

using namespace std;

int main()
{

  cout << "Welcome to FileAccelerator -- 2013" << endl;

  SETUP* ConfigFile = (SETUP*) new SETUP("/home/tony/Projects/FileAccelerator/config");

  if(!ConfigFile->mInitialise()){
    cout << "Error, could not open config file -> " << ConfigFile->mGetFileName() << endl;
    goto end;
  }



 end:
  delete ConfigFile;


  return 0;
}
