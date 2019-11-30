#include<iostream>

using namespace std;
class ActivityTime{
public:
    int start,end;
};
    int compare(ActivityTime a, ActivityTime b){
        return a.end<b.end;
    }


int max_activities(int starttime[],int endtime[],int n){
    ActivityTime arr[n];
    for(int i=0;i<n;i++){
        arr[i].start=starttime[i];

        arr[i].end=endtime[i];
    }
sort(arr,arr+n,compare);
int dynamicend=arr[0].end;
int activity_count=1;
for(int i=1;i<n;i++){
    if(arr[i].start>=dynamicend){
        dynamicend=arr[i].end;
        activity_count++;

    }
}
return activity_count;
}

int main()
{
    int starttime[]={7,0,4,3,4,6};
    int endtime[]={9,10,5,9,10,7};
    int n=6;
    cout<<max_activities(starttime,endtime,n);

    return 0;
}
