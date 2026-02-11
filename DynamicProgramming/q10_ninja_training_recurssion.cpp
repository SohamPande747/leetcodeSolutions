//BRUTE FORCE RECURSSION 

int func(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int pt = points[day][task] + func(day-1, task, points);
            maxi = max(maxi, pt);
        }
    } 
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    return func(n-1, 3, points);
}