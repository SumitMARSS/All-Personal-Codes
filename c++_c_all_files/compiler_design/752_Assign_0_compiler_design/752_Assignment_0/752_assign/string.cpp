#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <vector<string>> v;
    string str;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter the no. of variables : ";
    int n;
    cin>>n;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter the variables now"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter variable no. "<<i+1<<" now : ";
        cin>>str;
        v.push_back({str});
    }
    cout<<"---------------------------------"<<endl;
    for(int i=0;i<v.size();i++) {
        int m;
        cout<<"Enter no. of rules for "<<v[i][0]<<" : ";
        cin>>m;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter rule for "<<v[i][0]<<" now (USE i FOR id)"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int k=0;k<m;k++){
            string s;
            cout<<"Rule no "<<k+1<<" : ";
            cin>>s;
            v[i].push_back(s);
        } 
        cout<<"---------------------------------"<<endl;
    }
    cout<<"---------------------------------"<<endl;
    cout<<"Grammar Used"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++) {
            if(j==0) cout<<v[i][j]<<" -> ";
            else if(j!=v[i].size()-1) cout<<v[i][j]<<" | ";
            else cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<"---------------------------------"<<endl;
    cout<<"Enter the input string (TAKE id AS i AS EARLIER) : ";
    string inp,tmp,c;
    cin>>inp;
    cout<<"---------------------------------"<<endl;
    vector<string> stk;
    cout<<"Stack\t\t Input string \t\t Action"<<endl;
    tmp=inp[0];
    stk.push_back(tmp);
    inp.erase(0,1);
    tmp.clear();
    for(int i=0;i<stk.size();i++) tmp+=stk[i];
    cout<<"$"<<tmp<<"\t\t "<<inp<<"\t\t\t shift"<<endl;
    bool flag=true;
    while(flag){
        bool t=false;
        tmp.clear();
        if(stk.size()>=3){
        for(int i=0;i<stk.size();i++) tmp+=stk[i];
        //cout<<tmp<<endl;
        for(int i=0;i<v.size();i++) {
            for(int j=1;j<v[i].size();j++){
                //cout<<v[i][j]<<"  "<<tmp<<endl;
                if(v[i][j]==tmp){
                    for(int k=0;k<tmp.size();k++) stk.pop_back();
                    stk.push_back(v[i][0]);
                    t=true;
                    cout<<"$";
                    for(int i=0;i<stk.size();i++) cout<<stk[i];
                    cout<<"\t\t "<<inp<<"\t\t\t "<<v[i][0]<<" -> "<<v[i][j]<<endl;
                }
            }
        }}
         

        if(t==false){
            tmp.clear();
            int top=stk.size()-1;
            tmp=stk[top];
            bool t1=false;
            for(int i=0;i<v.size();i++) {
                for(int j=1;j<v[i].size();j++){
                    if(v[i][j]==tmp){
                        stk.pop_back();
                        stk.push_back(v[i][0]);
                        t1=true;
                        cout<<"$";
                        for(int i=0;i<stk.size();i++) cout<<stk[i];
                        cout<<"\t\t "<<inp<<"\t\t\t "<<v[i][0]<<" -> "<<v[i][j]<<endl;
                        break;
                    }
                    else if(v[i][0]==tmp or tmp=="+" or tmp=="*" or tmp=="(" or tmp==")" or tmp=="," or tmp=="/" or tmp=="-"){
                        c=inp[0];
                        stk.push_back(c);
                        inp.erase(0,1);
                        t1=true; 
                        cout<<"$";
                        for(int i=0;i<stk.size();i++) cout<<stk[i];
                        cout<<"\t\t "<<inp<<"\t\t\t shift"<<endl;
                        break;
                    } 
                }
                if(t1) break;
            }
            if(t1==false) t=false;
            else t=true; 
        }
        if(t==false) flag=false;
    }
    cout<<"---------------------------------"<<endl;
    cout<<"---------------------------------"<<endl;
    
        bool accepted = false;
        if (stk.size() == 1 && stk[0] == "$" && inp.empty()) {
            accepted = true;
            cout << "String Accepted" << endl;
        } else {
            cout << "String Rejected" << endl;
        }
    return 0;
}