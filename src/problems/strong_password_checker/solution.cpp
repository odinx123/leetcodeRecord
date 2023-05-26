class Solution {
public:
    // 連續的可以用插入、刪除、取代讓他不連續
    // 多一個字元多一步，少一個字元少一步(連續少配合插入、多配合刪除)
    // 沒有大寫一步，沒有小寫一步(連續可以配合置換)

    // 先計算大小寫數字並查看能不能用取代的消除連續
    // 如果大小寫數字還有剩，如果多刪除及插入都要，如果少就用插入的
    // 如果連續的還有剩，字數如果多就刪除，如果少就
    // 計算有沒有多或少，如果多且連續，看能不能刪除，如果少看能不能插入
    // n個重複的就除3->每兩個取代一個EX:aabaabaa
    int strongPasswordChecker(string password) {
        int cnt = 0;
        int cNum = password.size();
        vector<int> arr;
        
        bool have_up = false;
        bool have_lo = false;
        bool have_dig = false;
        for (int i = 0; i < cNum; ++i) {
            if (password[i] >= 'a' && password[i] <= 'z')
                have_lo = true;
            else if (password[i] >= 'A' && password[i] <= 'Z')
                have_up = true;
            else if (password[i] >= '0' && password[i] <= '9')
                have_dig = true;
            
            int j = i + 1;
            while (j < cNum && password[j] == password[i])
                ++j;
            
            if (j >= i+3)  // 扣掉原點i，j不用減1
                arr.push_back(j - i);
            i = --j;  // 一樣的不用再判斷大小寫跟數字
        }

        int miss = (!have_lo + !have_up + !have_dig);
        if (cNum < 6) {
            int diff = 6 - cNum;
            
            // 如果差比較多，那add的都剛好補進去
            // 如果有連續剛好插入中間
            cnt += max(diff, miss);
        } else {  // 6以上
            /*
            1. 字元數量符合:
                用缺少的取代重複的
            2. 字元數量不符合:
                先做刪除的動作，最多刪除到字元數等於20(餘數2)，因為假如有還有重複的，
                那用取代的更好(餘數2以上)，如果用刪除的最多跟取代同樣步數
                (並且可能會比較多步)。
            解釋: 如果餘數是0，刪除一個連續字元的滿足兩個條件，如果餘數是1，刪除兩個
            連續字元可以滿足兩個條件，如果餘數是2，刪除3個字元可以滿足兩個條件，刪除
            3個字元後就會一直是餘數2，EX:8-3=5，5%3=2
            所以如果over>0且只剩下餘數=2的連續字元，那麼需要先把over變成0也就是需要
            一定要刪除的部分，而只要其中一組連續的字元還沒剩下兩個且over都大於0，那
            對哪組字元做刪除跟對別組字元做刪除是一個意思(都要刪除3個字元才有用)

            測資: "1337C0d3bbeescctaaaaa" 21個字
                  "1337C0d3bbeescctaaaaaa" 22個字
                  "1337C0d3bbeesccttaaaa" 21個字
            */
            
            int over = max(cNum - 20, 0), left = 0;
            // over > 0代表超過才要執行這邊，因為剩下連續的部分用取代的更好
            // k==2要3步才可以消除，如果over==1，但刪除一個在取代只要2步
            // 如果over==2，刪除兩個在取代要3，over>=3才會有利
            for (int k = 0; over > 0 && k < 2; ++k) {   // k是餘數
                for (int i = 0; over > 0 && i < arr.size(); ++i) {
                    // %3==0會是最少步數符合條件的，DEL後會變%3==1以此類推
                    if (arr[i] < 3 || arr[i] % 3 != k) continue;
                    
                    // 超過的字數來減
                    arr[i] -= (k+1);
                    over -= (k+1);
                    cnt += (k+1);
                }
            }

            // 餘數是2的連續的減去3個字元可以少兩個連續字元
            cnt += max(over, 0);  // 接下來超過的是一定要減去的，餘數1的會是可能是負的
            for (int i = 0; i < arr.size(); ++i) {
                // arr[i]餘數一定是2
                if (arr[i] >= 3 && over > 0) {
                    int del = arr[i] - 2;  // 本組連續字元最多可刪除的字元
                    
                    // 餘數從0到2都是取代一個位置就可以滿足條件，而剩下的只有餘數2的
                    // 更優的條件前面一個迴圈已經用掉了(餘數更小的)，所以刪除到剛好在
                    // 取代在所有情況下步數一定是小於等於其他情況
                    // cnt += over;  // 可能沒有連續的所以用在外面(反正都是刪除over)
                    arr[i] -= over;
                    
                    // 只要最多可刪除字元有超過over之後都可用取代的
                    over -= del;
                }
                // left是計算剩下的連續字元需要多少個替換
                if (arr[i] >= 3) left += arr[i] / 3;
            }
            // cout << "cnt: " << cnt << endl;
            // cout << "miss: " << miss << endl;
            // cout << "left: " << left << endl;
            
            cnt += max(miss, left);
        }

        return cnt;
    }
};