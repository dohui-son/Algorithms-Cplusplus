﻿//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void BT(int& ans,vector<vector<int>>&ad,int waste,int start, vector<bool>&vis, int cnt ) {
//    if (cnt == ad.size()) { 
//        ans = min(ans, waste); }
//    for (int i = 0; i < ad.size(); i++)
//    {
//        if (vis[i] == false) {
//            if (start == -1) {
//                vis[i] = true;
//                BT(ans, ad, waste,ad[i][0], vis, cnt+1);
//                vis[i] = false;
//            }
//            else {
//                if (start + 4 < ad[i][0]) {
//                    vis[i] = true;
//                    BT(ans, ad, waste,ad[i][0],vis,cnt+1);
//                    vis[i] = false;
//                }
//                else {
//                    vis[i] = true;
//                    waste += (start + 5 - ad[i][0]) * ad[i][1];
//                    BT(ans, ad, waste, start+5, vis, cnt+1);
//                    vis[i] = false;
//                    waste -= (start + 5 - ad[i][0]) * ad[i][1];
//
//                }
//
//            }
//        }
//    }
//}
//
//int solution(vector<vector<int>> ads) {
//    int answer = 987654321;
//    int w = 0;
//    vector<bool>visit(5000, false);
//    BT(answer, ads,-1, 0,visit,0);
//    //BT(int& ans, vector<vector<int>>&ad, int waste, int start, vector<bool>&vis, int cnt)
//    
//
//
//    return answer;
//}
//
//int main() {
//    vector<vector<int>> v= { {5,2},{2,2},{6,3},{9,2} };
//
//    cout << solution(v);
//
//
//    return 0;
//}
//
//
////문제 설명
////LINE AD Platform의 개발자 "브라운"은 LINE을 사용하는 유저에게 어떤 순서로 광고를 노출할지 고민하고 있습니다.
////
////광고는 각각[노출할 수 있는 시작 시간, 대기 시간당 손해 비용]으로 구성됩니다.한 번에 하나의 광고만 노출할 수 있고, 특정 시점에 노출할 수 있는 광고가 하나 이상 존재하면 반드시 노출해야 합니다.또한 노출하기 시작한 광고는 노출 시간이 끝날 때까지 중단할 수 없으며, 모든 광고는 정확히 5s의 시간 동안 노출합니다.
////
////예를 들어, [A:1s 시점부터 노출할 수 있는 광고, B : 3s 시점부터 노출할 수 있는 광고, C : 5s 시점부터 노출할 수 있는 광고]와 같은 광고들이 있다고 가정해 보겠습니다.
////
////스크린샷 2021 - 04 - 20 오전 4.39.45.png
////
////한 번에 하나의 광고만 노출할 수 있고 노출하기 시작한 광고는 중단할 수 없기 때문에 광고를 노출할 수 있는 시작 시간 순서대로 처리하면 다음과 같습니다.
////
////스크린샷 2021 - 04 - 20 오전 4.41.00.png
////
////광고 A는 0s, B는 3s, C는 6s의 대기 시간이 발생하며, 광고 A, B, C의 대기 시간당 손해 비용이 각각 2, 1, 3일 경우 총 손해 비용은(0 * 2) + (3 * 1) + (6 * 3) = 21이 됩니다.이를 시간대 별로 확인하면 다음과 같습니다.
////
////시간	노출될 수 있는 광고	손해비용	총 손해비용
////0 - 0	0
////1	A	0	0
////6	B, C	3 * 1 + 1 * 3 = 6	6
////11	C	5 * 3 = 15	6 + 15 = 21
////16 - 0	21
////"브라운"은 총 손해 비용이 최소가 되도록 광고를 처리하려고 합니다.[노출할 수 있는 시작 시간, 대기 시간당 손해 비용]으로 구성된 2차원 배열의 광고 리스트 ads를 입력받았을 때, 최소가 되는 총 손해 비용을 반환해 주세요.
////
////제한 사항
////ads의 길이는 1 이상 5, 000 이하입니다.
////ads는 광고 각각에 대해[노출할 수 있는 시작 시간, 대기 시간당 손해 비용]을 담은 2차원 배열입니다.
////각 광고를 노출할 수 있는 시작 시간은 0 이상 25, 000 이하입니다.
////대기 시간당 손해 비용은 1 이상 10 이하입니다.
////모든 광고의 노출 시간은 5s 입니다.
////입출력 예
////ads	return
////[[1, 3], [3, 2], [5, 4]] 20
////[[0, 3], [5, 4]] 0
////[[0, 1], [0, 2], [6, 3], [8, 4]] 40
////[[5, 2], [2, 2], [6, 3], [9, 2]] 33