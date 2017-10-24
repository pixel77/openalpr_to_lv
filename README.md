# OpenALPR 2.3 integrated to LabVIEW
This project is help to integrate the OpnelALPR open source ALPR system to LabVIEW (for LV 2014 or newer versions).
Everything is documented in the LV and C++ codes, if you want to find more information about the project, what this readme contains. The project also contains a html help for the example LW program, which could be find in the Help directory in the project.

The softver uses the OpenALR. You can finfd the original, newest code here: https://github.com/openalpr/openalpr, and it's licenced by  the Affero GPLv3 Licence, so that makes this programs every C++ programs parts, wich contains the part of their progam also Affero GPLv3 Licenced http://www.gnu.org/licenses/agpl-3.0.html. And the other codes(LabVIEW) of the projects are under the CC BY-SA Licence https://creativecommons.org/licenses/by-sa/3.0/deed.en. The OpenALPR Library's files (the openlapr_32 and the DLL folders), and any other linked sources (url, ftp,..) in the project are could be under the Copyright or other Licences of the rigthfull owners.

Important!
The „openalpr_32” directory contains the 2.3 version of the OpnelALPR open source ALPR system.
For the sucesfull operation please copy the „openalpr_32” directory to C:/ in a folder (or whether you want). And create a "OPENALPR_PATH" environment variable, which have to point to the directory which contains the "openalpr_32" directory. The environment variable’s value must be the path of the directory, which contains the „openalpr_32” directory, not the „openalpr_32” directory’s path itself. (eg. “C:\OpenALPR\alpr_32”, where the “OPENALPR_PATH” environment variable’s value is “C:\OpenALPR”)

Created by Vágner Máté, Hungary. http://smartmark.hu/
