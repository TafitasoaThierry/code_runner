#include <iostream>

#define MAX_FILE_NAME 200
#define MAX_LANGUANGE_NAME 5

static char language_1[MAX_LANGUANGE_NAME] = "c";
static char language_2[MAX_LANGUANGE_NAME] = "cpp";
static char language_3[MAX_LANGUANGE_NAME] = "py";
static char language_4[MAX_LANGUANGE_NAME] = "java";
static char language_5[MAX_LANGUANGE_NAME] = "js";

static bool equal(char *c_1, char *c_2, int n){
    for(int i = 0; i < n; i++){
        if(c_1[i] != c_2[i]){
            return false;
        }else if(c_1[i] == c_2[i] && c_2[i] == '\0'){
            return true;
        }
    }
    return true;
}

static std::string get_input_file(char *file){
    std::string result = "";
    for(int i = 0; i < MAX_FILE_NAME; i++){
        if(file[i] != '.'){
            result += file[i];
        }else{
            break;
        }
    }
    return result;
}

class Language{
    private:
        char *file = nullptr;
        char *name = nullptr;
    
    public:
        Language(char *file, char *name){
            this->file = file;
            this->name = name;
        }
        bool is_compiled(){
            if((equal(this->name, language_1, MAX_LANGUANGE_NAME)) || (equal(this->name, language_2, MAX_LANGUANGE_NAME)) || (equal(this->name, language_4, MAX_LANGUANGE_NAME))){
                return true;
            }else{
                return false;
            }
        }
        int to_compile(){
            std::string cmd = "";
            const char *exec = nullptr;
            int code_result = 1;
            if(equal(this->name, language_1, MAX_LANGUANGE_NAME)){
                cmd = "gcc -o ";
                cmd += get_input_file(this->file);
                cmd += " ";
                cmd += this->file;
                exec = (cmd).c_str();
                //std::cout << "cmd to compile is = " << cmd << std::endl;
                //std::cout << "exec file = " << get_input_file(this->file) << std::endl;
                code_result = system(exec);
            }else if(equal(this->name, language_2, MAX_LANGUANGE_NAME)){
                cmd = "g++ -o ";
                cmd += get_input_file(this->file);
                cmd += " ";
                cmd += this->file;
                exec = (cmd).c_str();
                code_result = system(exec);
            }else{
                cmd = "javac ";
                cmd += this->file;
                exec = (cmd).c_str();
                code_result = system(exec);
            }
            return code_result;
        }
        void to_exec(){
            std::string cmd = "";
            const char *exec = nullptr;
            if(equal(this->name, language_1, MAX_LANGUANGE_NAME) || equal(this->name, language_2, MAX_LANGUANGE_NAME)){ // c and cpp
                cmd = get_input_file(this->file);
                exec = (cmd).c_str();
                system(exec);
            }else{
                cmd = "java ";
                cmd += get_input_file(this->file);
                exec = (cmd).c_str();
                system(exec);
            }
        }
        void show_message(){
            std::cout << "DANGEROUS !" << std::endl;
        }
        void to_interpret(){
            std::string cmd = "";
            const char *exec = nullptr;
            if(equal(this->name, language_3, MAX_LANGUANGE_NAME)){ // py
                cmd = "python ";
                cmd += this->file;
                exec = (cmd).c_str();
                system(exec);
            }else{ // js
                cmd = "node ";
                cmd += this->file;
                exec = (cmd).c_str();
                system(exec);
            }
        }
};

char *get_name(char *file){
    for(int i = 0; i < MAX_FILE_NAME; i++){
        if(file[i] == '.'){
            return &file[i+1];
        }
    }
    return 0;
}

using namespace std;

int main(int argv, char *argc[]){
    char *file = argc[1];
    char *name = get_name(file);
    Language language(file, name);

    if((equal(name, language_1, MAX_LANGUANGE_NAME)) || (equal(name, language_2, MAX_LANGUANGE_NAME)) || (equal(name, language_3, MAX_LANGUANGE_NAME)) || (equal(name, language_4, MAX_LANGUANGE_NAME)) || (equal(name, language_5, MAX_LANGUANGE_NAME))){
        language.is_compiled() ? (language.to_compile() == 0 ? language.to_exec() : language.show_message()) : language.to_interpret();
    }else{
        cout << "Language Not Supported by RUN command!" << endl;
    }
    
    return 0;
}