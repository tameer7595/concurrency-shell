#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <sys/wait.h>

using namespace std;
void split(const std::string &s, char delim, std::vector<std::string> &elems);

void  split(const std::string &s, char delim,char **res) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    int i=0;
    for(i=0 ; i < elems.size() ; i++){
        res[i] = (char*)elems[i].c_str();
    }
    res[i] = NULL;
}

int main() {
    char* cmd[128];
    std::string input;
    char *argv[10];
    std::cout << "Hello, World!" << std::endl;
    while (1) {
        std::cout << ">>> " << std::endl;
        getline(std::cin, input);
        split(input,' ',cmd);
        int i=0;

        while(cmd[i]!=NULL){

            i++;
        }
        pid_t pr = fork();
        if (pr == 0) {
            if (execvp(cmd[0], (cmd ))<0) {
                std::cout << "execvp failed!!!"<<std::endl;
                exit(0);
            }
        }

        if(*cmd[i-1]=='&')
            wait(&pr);
    }
    return 0;
}
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
