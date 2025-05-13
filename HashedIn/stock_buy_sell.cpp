#include<iostream>
#include<vector>
using namespace std;
int maxProfitRec(vector<int> &prices, int start, int end)
{
    int res = 0;
    for(int i = start;i<end;i++)
    {
        for(int j = i+1;j<=end;j++)
        {
            if(prices[j]>prices[i])
            {
                int curr = (prices[j]-prices[i]) +
                maxProfitRec(prices, start, i-1)+
                maxProfitRec(prices, j+1, end);

                res = max(res, curr);
            }
        }
    }
    return res;
}
int maxProfit(vector<int> &prices)
{
    return maxProfitRec(prices, 0, prices.size()-1);
}
int main()
{
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout<<maxProfit(prices)<<endl;
    return 0;
}