#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         int length = nums.size();
//         vector<int> res_vec;
//         for (int i = 0;i< length;i++){
            
//             for (int j = i+1;j<length;j++){
                
//                 if (nums[i] + nums [j] == target){

//                     res_vec.push_back(i);
//                     res_vec.push_back(j);
//                     return res_vec;
//                 }

//             }
//         }
//         return res_vec;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int length = nums.size();
        vector<int> res_vec;

        map<int,vector<int>> helloMap;
        
        for (int i = 0;i < nums.size();i++){
            if (helloMap.count(nums[i])){
                helloMap[nums[i]].push_back(i);
            }else{
                helloMap[nums[i]] = vector<int>({i});
            }
        }

        for (map<int,vector<int>>::iterator pBegin = helloMap.begin();pBegin!=helloMap.end();pBegin++){
            // cout << pBegin->first << endl;

            int left = target - pBegin->first;

            if (left > 0 && helloMap.count(left) > 0){

                vector<int> temp_vec = helloMap[left];

                if (temp_vec.size() == 1 && temp_vec[0] != pBegin->first){
                    return vector<int>({temp_vec[0],pBegin->first});
                }else if(temp_vec.size() > 1){
                    return pBegin->second;
                }

                return res_vec;
            }

        }

        return res_vec;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution solution;
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    // vec.push_back(4);
    // vec.push_back(5);

    vector<int> result_vec = solution.twoSum(vec,6);

    for (auto &&res : result_vec)
    {
        cout << res << endl;
    }
    
    
    return 0;
}
