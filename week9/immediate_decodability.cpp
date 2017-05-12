#include <iostream>
#include <cstring>
using namespace std;

bool check_overlap(const char *a, const char *b) {
    const char *ss, *ls;
    if (strlen(a) < strlen(b)) {
        ss = a;
        ls = b;
    } else if(strlen(a) > strlen(b)) {
        ss = b;
        ls = a;
    } else {
        return strcmp(a, b) == 0;
    }
    
    for (int i = 0; i < strlen(ss); i++) {
        if (ss[i] != ls[i])
            return false;
    }
    
    return true;
}

int main() {
    char codes[100][100];
    char tmp_code[10];
    int set_count = 0;
    while(1) {
        set_count++;
        int code_count = 0;
        while(scanf("%s", tmp_code), strcmp(tmp_code, "9") != 0) {
            strncpy(codes[code_count++], tmp_code, 10);
        }
        if (!code_count)
            break;
        
        bool decodable = true;
        for (int i = 0; i < code_count - 1; i++) {
            for (int j = i + 1; j < code_count; j++) {
                if (check_overlap(codes[i], codes[j]))
                    decodable = false;
            }
            if (!decodable)
                break;
        }
        
        if (decodable)
            printf("Set %d is immediately decodable\n", set_count);
        else
            printf("Set %d is not immediately decodable\n", set_count);
    }
    return 0;
}