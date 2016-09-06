#include "FileType.h"

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    DIR* dir;
    struct dirent* ent;
    string dir_name = "fixture";
    if ((dir = opendir(dir_name.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] == '.')
                continue;

            string file_name = dir_name + "/" + string(ent->d_name);
            ifstream ifs(file_name.c_str(), ios::binary);
            string buf((istreambuf_iterator<char>(ifs)),
                (istreambuf_iterator<char>()));

            string ext = "";
            int index = 0;
            if ((index = file_name.rfind('.'))) {
                ext = file_name.substr(i + 1);
            }

            string type = "";
            string mime = "";
            bool ret = FileType(string(buf), type, mime);

            string result = type == ext ? "[OK]" : "[ERR]";
            cout<<result<<"\t"<<ent->d_name<<"\t"<<type<<"\t"<<mime<<"\t"<<ret<<endl;
        }
        closedir(dir);
    }
    
    return 0;
}
