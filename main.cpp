#include <iostream>
#include <vector>
#include "seedwires.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Lets start"<<endl;
    cout<<"Write number of slots"<<endl;
    int n;
    cin>>n;
    vector <vector<int>> distance(n);
    for( int j = 0; j < n; ++j ) {
            distance[j].resize(n);
        }

    int count=0;
    for (int i=0;i<n;i++) {
        for (int q=0;(q+count)<n;q++) {
            if(i!=(q+count)) {
                cout<<"Write distance between "<<i<<" and "<<count+q<<"componet"<<endl;
            cin>>distance[i] [count+q];
            distance [count+q] [i]=distance[i] [count+q];
            }
            else
                distance[i] [count+q]=0;
        }
        ++count;
    };
    count=0;
    vector <vector<int>> wires(n);
    for( int j = 0; j < n; ++j ) {
            wires[j].resize(n);
        }

    for (int i=0;i<n;i++) {
        for (int q=0;(q+count)<n;q++) {
            if(i!=(q+count)) {
             cout<<"Write wires number between "<<i<<" and "<<count+q<<"componet"<<endl;
            cin>>wires[i] [count+q];
            wires [count+q] [i]=wires[i] [count+q];
            }
            else
                wires[i] [count+q]=0;
        }
        ++count;
    };
    vector<int> posibility;
    for (int p=0;p<n;p++)
        posibility.push_back(p);
vector<int> place;
int bestS=0;
cout<<"Distance matrix"<<endl;
for (int i=0;i<n;++i) {
    for (int q=0;q<n;++q) {
        cout<<distance[i] [q]<<" ";
    }
    cout<<endl;
}
cout<<"Wires matrix"<<endl;
for (int i=0;i<n;++i) {
    for (int q=0;q<n;++q) {
        cout<<wires[i] [q]<<" ";
    }
    cout<<endl;
}

spaceComponents(distance,wires,posibility,place,bestS);

    return 0;
}
