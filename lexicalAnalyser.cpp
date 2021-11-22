#include<bits/stdc++.h>

using namespace std;

bool isCharOrNum(char a){
    if ((64 < a && a < 91) || (96 < a && a < 123) || (47 < a && a < 58) || a== 46){
        return true;
    }
    return false;
}

int main(void){

    //string str = "int i =0 j=2.44; if(i<j){cout<<\"fucu\"}:[";
    int i=0,j=0,k =0;
    char str[5];
    FILE *fptr = fopen("sample.zzz","r");
    string temp;
    bool signal;
    vector<string> str1;
    string brack = "{}[]()%,;:";
    string oper = "+-*/=<>";  // operator that can work one or two together

    str[1] = fgetc(fptr);
    str[2] = fgetc(fptr);

    while(str[1] != EOF){

        if(isCharOrNum(str[1])){
            temp.push_back(str[1]);

        }else if(str[1] == ' ' && isCharOrNum(str[0])){
            //cout<<"INside "<<str[0]<<" "<<str[1]<<" "<<str[2]<<endl;
            str1.push_back(temp);
            temp.erase();
            j++;

        }else if(brack.find(str[1]) != string :: npos){
            if(isCharOrNum(str[0])){
                str1.push_back(temp);
                temp.erase();
                j++;
            }
            temp.push_back(str[1]);
            str1.push_back(temp);
            temp.erase();
            j++;
            
        }else if (oper.find(str[1]) != string :: npos){
            if(isCharOrNum(str[0])){
                str1.push_back(temp);
                temp.erase();
                j++;
            }
            temp.push_back(str[1]);
            str1.push_back(temp);
            temp.erase();
            j++;
            if(oper.find(str[2]) != string :: npos){
                //i++;
                str[0] = str[1];
                str[1] = str[2];
                str[2] = fgetc(fptr);

                temp.push_back(str[1]);
                str1.push_back(temp);
                temp.erase();
                j++;

            }

        }else if(str[1] == 34){
            if(isCharOrNum(str[0])){

                str1.push_back(temp);
                temp.erase();
                j++;
            }
            temp.push_back(str[1]);
            //i++;
                str[0] = str[1];
                str[1] = str[2];
                str[2] = fgetc(fptr);

            while(str[1] != 34){
                temp.push_back(str[1]);
                //i++;
                str[0] = str[1];
                str[1] = str[2];
                str[2] = fgetc(fptr);

            }

            temp.push_back(str[1]);
            str1.push_back(temp);
            temp.erase();
            j++;

        }

        //i++;
        str[0] = str[1];
        str[1] = str[2];
        str[2] = fgetc(fptr);
    }

    cout<<"No of tokens : "<<j<<endl;

    for(int l =0;l<j;l++){

        cout<<str1[l]<<endl;
    }

}


