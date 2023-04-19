#include <bits/stdc++.h>
using namespace std;
#define pkt pair<long long int, long long int>
vector<pkt> gura;
vector<pkt> dol;
void sg(vector<pkt> A) {
    long long int n=A.size();
    for(long long int k = 0; k < n-1; k++) {
        for(long long int i = 0; i < n-k-1; i++) {
            //cout << "sprawdzam"<< A[i].first << " " << A[i].second << " z " << A[i+1].first << " " << A[i+1].second <<endl;
            if (A[i].first*A[i+1].second > A[i+1].first*A[i].second) {
                //cout << "zamien" <<endl;
                swap(A[i], A[i+1]);
            }
            else if(A[i].first*A[i+1].second==A[i+1].first*A[i].second) {
                //cout << "te same"<<endl;
                if(abs(A[i].first)>abs(A[i+1].first)) {

                    swap(A[i], A[i+1]);
                }
            }

        }
    }
    gura=A;
}
void sd(vector<pkt> A) {
    long long int n=A.size();
    for(long long int k = 0; k < n-1; k++) {
        for(long long int i = 0; i < n-k-1; i++) {
            //cout << "sprawdzam"<< A[i].first << " " << A[i].second << " z " << A[i+1].first << " " << A[i+1].second <<endl;
            if (A[i].first*A[i+1].second > A[i+1].first*A[i].second) {
                //cout << "zamien" <<endl;
                swap(A[i], A[i+1]);
            }
            else if(A[i].first*A[i+1].second==A[i+1].first*A[i].second) {
                //cout << "te same"<<endl;
                if(abs(A[i].first)<abs(A[i+1].first)) {

                    swap(A[i], A[i+1]);
                }
            }

        }
    }
    dol=A;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int xe;
    cin>>xe;
    for(long long int d=0;d<xe;d++) {
        long long int x,y;
        cin>>x>>y;
        pkt p=make_pair(x,y);
        pkt l=make_pair(x,y*-1);
        if(y>0) gura.push_back(p);
        else if(y<0) dol.push_back(l);
        else {
            if(x<0) gura.push_back(p);
            else dol.push_back(l);
        }
    }
    sg(gura);
    sd(dol);

    for(long long int d=dol.size()-1;d>=0;d--) {
        cout << dol[d].first << " " << (dol[d].second)*-1<<endl;
    }
    for(long long int d=0;d<gura.size();d++) {
        cout << gura[d].first << " " << gura[d].second<<endl;
    }


}