/*****************************************************************************
 *                                                                           *
 * setup.h                                                                   *
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
#include <string>
using namespace std;

class SETUP{
 public:

  SETUP(const char* FileName);

  string* mGetFileName(void);
  string* mGetFileVersion(void);

  int mInitialise(void);
  
  void mSetFileVersion(string FileVersion) \
  {strFileVersion = FileVersion;}

  void mSetDate(string FileDate) \
  {strDate = FileDate;}

  void mSetSrcIpAddress(string SrcIpAddress)	\
  {strSrcIpAddress = SrcIpAddress;}
  
  void mSetSrcPortAddress(string SrcPortAddress)\
  {strSrcPortAddress = SrcPortAddress;}
  
  void mSetDstIpAddress(string DstIpAddress)\
  {strDstIpAddress = DstIpAddress;}
  
  void mSetDstPortAddress(string DstPortAddress)\
  {strDstPortAddress = DstPortAddress;}
  

  ~SETUP(void);

private:
  string mFileName;
  string strFileVersion;
  string strDate;
  string strSrcIpAddress;
  string strSrcPortAddress;
  string strDstIpAddress;
  string strDstPortAddress;
};

