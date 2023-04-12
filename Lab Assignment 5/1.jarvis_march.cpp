#include <bits/stdc++.h>
using namespace std;

// orientation from point p1-p2 and p2-p3
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

int distance(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{

    int x1 = p1.first - p2.first;
    int y1 = p1.second - p2.second;

    int x2 = p1.first - p3.first;
    int y2 = p1.second - p3.second;

    int distance12 = (y1 * y1 + x1 * x1);
    int distance13 = (y2 * y2 + x2 * x2);

    if (distance12 == distance13)
        return 0;

    else if (distance12 < distance13)
        return 1;

    else
        return -1;
}

pair<int, int> minX(vector<pair<int, int>> &points)
{

    pair<int, int> p = points[0];
    for (auto it : points)
    {
        if (it.first < p.first)
            p = it;
    }

    return p;
}


//TC -> O(n*h) + O(n) => O(n*h)
//SC -> O(h)

//n-> no of point in points, h-> number of points in hull

vector<pair<int, int>> jarvis_march(vector<pair<int, int>> &points)
{

    pair<int, int> on_hull = minX(points);

    vector<pair<int, int>> hull;

    while (true)
    {
        hull.push_back(on_hull);
        pair<int, int> next_point = points[0];
        for (auto point : points)
        {
            int crs_product = orientation_crossProduct(on_hull, next_point, point);
            //the orientation (on_hull,next_point) to  (next_point,point) is anti-clockwise 
            //update the next_pont as point
            if (next_point == on_hull || crs_product == 1 || (crs_product==0 && distance(on_hull,point,next_point)==-1))
            {
                next_point = point;
            }
        }

        on_hull = next_point;

        if (on_hull == hull[0])
            break;
    }

    return hull;
}

int main()
{
    cout<<"Enter the number of points: ";
    int n, x, y;
    cin >> n;


    vector<pair<int, int>> points;
    cout<<"\n--Enter the points--\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    vector<pair<int, int>> convex_hull = jarvis_march(points);

    cout<<"\n\nConvex Hull created by the following points: "<<endl;
    for (auto point : convex_hull)
    {
        cout <<"( "<< point.first << " , " << point.second <<" )"<< endl;
    }

    return 0;
}