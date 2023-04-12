#include <bits/stdc++.h>
using namespace std;

#define PI 3.14;

double polar_angle(pair<int, int> &p1, pair<int, int> &p2)
{

    if(p1.second==p2.second)
        return -PI;

    int dy=p1.second-p2.second;
    int dx=p1.first-p2.first;

    return atan2(dy,dx);

}

double distance(pair<int, int> &p1, pair<int, int> &p2)
{

    int x1 = p1.first;
    int y1 = p1.second;

    int x2 = p2.first;
    int y2 = p2.second;

    int diffY=y2-y1;
    int diffX=x2-x1;
    double distance = sqrt(diffY*diffY+ diffX*diffX);

    return distance;
}


//TC -> O(n)
pair<int, int> minYminX(vector<pair<int, int>> &points)
{
    pair<int,int>p=points[0];
    
    for(auto point:points){
        if(point.second<p.second){
            p=point;
        }
        else if(point.second==p.second&&point.first<p.first){
            p=point;
        }
    }

    return p;
}

int orientation_crossProduct(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{

    int x1, y1, x2, y2, x3, y3;
    x1 = p1.first;
    y1 = p1.second;

    x2 = p2.first;
    y2 = p2.second;

    x3 = p3.first;
    y3 = p3.second;

    int d = (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);

    //counterclock-wise
    if (d > 0)
        return 1;

    //clockwise
    else if (d < 0)
        return -1;
    //collinear
    else
        return 0;
}




//TC -> O(n) + O(2n) + O(nlogn) => O(n*logn)
vector<pair<int, int>> graham_scan(vector<pair<int, int>> &points)
{

    pair<int,int>minYminXP = minYminX(points);      

    //store polar_angle and distance in pair and sort it 
    // so we'll get point, i.e, value of mp in ascending order of keys
    map<pair<double,double>,pair<int,int>>mp;
    for(auto point:points){

        double plr_ang=polar_angle(minYminXP,point);
        double dis=distance(minYminXP,point);

        mp[{plr_ang,dis}]=point;

    }
    

    vector<pair<int,int>>hull;

    for(auto p:mp){
        int h=hull.size();
        pair<int,int>point=p.second;

        //the orientation (hull[h-2],hull[h-1]) to  (hull[h-1],point) is clockwise 
        //pop-the hull[h-1]

        //in graham scan when you get, direction anti-clockwise stop popping
        // but in jarvis if you get anti-clock wise keep updating
        while(h>=2 && orientation_crossProduct(hull[h-2],hull[h-1],point)!=1){
            hull.pop_back();
            h=hull.size();
        }


        hull.push_back(point);
    }


    return hull;
    
}

int main()
{
    cout<<"Enter the number of points: ";
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> points;
    cout<<"Enter the points \n ";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }
     
    
    vector<pair<int, int>> convex_hull = graham_scan(points);
    cout<<"\n\nConvex Hull created by the following points: "<<endl;
    for (auto point : convex_hull)
    {
       cout <<"( "<< point.first << " , " << point.second <<" )"<< endl;
    }

    return 0;
}