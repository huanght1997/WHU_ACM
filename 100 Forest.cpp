#include<stdio.h>  
#include<iostream>  
#include<string>  
using namespace std;  
  
  
int main(){  
    char* ss[8] = {"littleken", "knuthocean", "dongfangxu", "zap", "kittig", "robertcui", "forest", "flirly" };  
    char s1[8] = { 'l', 'k', 'd', 'z', 'k', 'r', 'f', 'f' };  
    char s2[8] = { 'i', 'n', 'o', 'a', 'i', 'o', 'o','l' };  
    int next[8] = { 9, 10, 10, 3, 6, 9, 6, 6 };  
    int k;  
    cin >> k;  
    for (int h = 0; h < k; h++){  
        string t;  
        cin >> t;  
        int max = 0;  
        int flag = 0;  
        int ans[8] = { 0 };  
  
  
        for (string::iterator it = t.begin(); it != t.end();){  
            for (int i = 0; i < 8; i++){  
                if (*it == s1[i] && *(it + 1) == s2[i]){  
                    it += next[i];  
                    ans[i]++;  
                    break;  
                }  
            }  
        }  
  
        for (int i = 0; i < 8; i++){  
            if (max < ans[i])  
            {  
                max = ans[i];  
                flag = i;  
            }  
        }  
        printf("%s\n", ss[flag]);  
    }  
}  