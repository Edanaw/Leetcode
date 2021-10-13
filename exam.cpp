#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <memory.h>

using namespace std;

vector<string> getFileList(string dir)
{
    DIR *pathname = opendir(dir.c_str());

    if (pathname == NULL) {
        cout << "opendir failed" << endl;
    }

    vector<string> allPath;

    struct dirent *entry;

    while ((entry = readdir(pathname)) != NULL) {
        // dir
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            string dirNew = dir + "/" + entry->d_name;
            vector<string> tempPath = getFileList(dirNew);

            allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
        } else {
            string name = entry->d_name;
            string newDir = dir + "/" + name;
            allPath.push_back(newDir);
        }
    }

    closedir(pathname);
    return allPath;
}

int main()
{
    string dir =  "/home/wpb/test";
    vector<string> str = getFileList(dir);

    for (auto& v : str) {
        cout << v << endl;
    }
}
