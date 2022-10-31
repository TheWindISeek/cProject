#include "./ReadFile.h"
void std::ReadFile()
{
    FILE* fp = NULL;
    vector<string> v[10];
    string pre = "../";
    string answer = "answer/count";
    string suffix = ".out";
    string s;
    for(int i = 0; i < 10; i++)
    {
        string destination = pre + answer+i+suffix;
        fp = fopen(destination,"r");
        while(!feof(fp))
        {
            fscanf(fp,"%s",&s);
            v[i].push_back(s);
        }
        fclose(fp);
    }
    for(int i = 0; i < 10;i++)
    {
        for(string &s:v[i])
            cout << s<<'\n';
    }
}
int std::EqualNumber(vector<string>& answer,vector<string>& result)
{
    return 0;
}
