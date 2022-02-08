#include<bits/stdc++.h>
using namespace std;

void solve1(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        string tmp;
        cin >> tmp;
        if(tmp.substr(0,2)=="++"){
            ans++;
        }
        else if(tmp.substr(0,2)=="--"){
            ans--;
        }
        else if(tmp.substr(1,2)=="++"){
            ans++;
        }
        else if(tmp.substr(1,2)=="--"){
            ans--;
        }
    }
    cout << ans << "\n";
}

void solve2(){
    long long n;
    cin>>n;
    vector<int> minimizedDigits;
    while(n){
        int cornerDigit = n % 10;
        bool lastDigitAndItsNine = n < 10 && n==9;
        if(lastDigitAndItsNine) minimizedDigits.push_back(cornerDigit);
        else minimizedDigits.push_back(min(cornerDigit, 9 - cornerDigit));
        n /= 10;
    }
    long long ans = 0;
    while(minimizedDigits.size()){
        ans = ans*10 + minimizedDigits.back();
        minimizedDigits.pop_back();
    }
    cout << ans << "\n";
}

void solve3(){
    vector<vector<int>> m(5,vector<int>(5));
    int numi, numj;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5;j++){
            cin >> m[i][j];
            if(m[i][j]!=0){
                numi = i;
                numj = j;
            }
        }
    }
    cout << ( abs(2-numi)+abs(2-numj) ) << "\n";
}

void solve4(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int totalDrink = k * l;
    int totalLime = c * d;
    int totalSalt = p;

    int oneFriendDrink = nl;
    int oneFriendLime = 1;
    int oneFriendSalt = np;

    int numFriendsCanTakeDrink = totalDrink / oneFriendDrink;
    int numFriendsCanTakeLime = totalLime / oneFriendLime;
    int numFriendsCanTakeSalt = totalSalt / oneFriendSalt;

    int totalToasts = min({numFriendsCanTakeDrink, numFriendsCanTakeLime, numFriendsCanTakeSalt});
    cout << ( totalToasts/n ) << "\n";
}

void solve5(){
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    int ans = 300;
    for (int i = 1; i <= 100;i++){
        ans = min(ans, abs(i - x1) + abs(i - x2) + abs(i - x3));
    }
    cout << ans << "\n";
}

void solve6(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pow10 = 1;
        vector<int> ans;
        while(n){
            int cornerDigit = n % 10;
            if(cornerDigit!=0){
                ans.push_back(cornerDigit * pow10);
            }
            n /= 10;
            pow10 *= 10;
        }
        cout<<ans.size()<<"\n";
        while(ans.size()){
            cout << ans.back() << " ";
            ans.pop_back();
        }
        cout << "\n";
    }
}

void solve7(){
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;j++){
            int snake = 0;
            if(i%2==1) snake = 1;
            if(i%2==0 && (i/2)%2==1 && j==m) snake = 1;
            if(i%2==0 && (i/2)%2==0 && j==1) snake = 1;
            cout << (snake ? '#' : '.');
        }
        cout << "\n";
    }
}

void solve8(){
    map<string, int> faces;
    faces["Tetrahedron"] = 4;
    faces["Cube"] = 6;
    faces["Octahedron"] = 8;
    faces["Dodecahedron"] = 12;
    faces["Icosahedron"] = 20;
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        string tmp;
        cin >> tmp;
        ans += faces[tmp];
    }
    cout << ans << "\n";
}

void solve9(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 1;
    int mn = 100;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
        mn = min(mn, a[i]);
    }
    int leftMostMaxElementIdx = 101;
    for (int i = 0; i < n;i++){
        if(a[i]==mx){
            leftMostMaxElementIdx = i;
            break;
        }
    }
    int rightMostMinElementIdx = -1;
    for (int i = n-1; i >= 0;i--){
        if(a[i]==mn){
            rightMostMinElementIdx = i;
            break;
        }
    }
    int ans = (leftMostMaxElementIdx - 0) + (n - 1 - rightMostMinElementIdx);
    if(leftMostMaxElementIdx>rightMostMinElementIdx) ans--;
    cout << ans << "\n";
}

void solve10(){
    int n;
    cin >> n;
    string ans="EASY";
    for (int i = 1; i <= n;i++){
        int num;
        cin>>num;
        if(num) ans = "HARD";
    }
    cout << ans << "\n";
}

void solve11(){
    int n;
    cin>>n;
    vector<int> ans(n+1);
    for (int i = 1; i <= n;i++){
        int tmp;
        cin >> tmp;
        ans[tmp] = i;
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

void solve12(){
    string num;
    cin >> num;
    int luckyDigits = 0;
    for(char i:num){
        if(i=='4' || i=='7') luckyDigits++;
    }
    if(luckyDigits<1){
        cout<<"NO\n";
        return;
    }
    while(luckyDigits){
        int cornerDigit = luckyDigits % 10;
        if(cornerDigit!=4 && cornerDigit!=7){
            cout<<"NO\n";
            return;
        }
        luckyDigits /= 10;
    }
    cout << "YES\n";
}

void solve13(){
    int n;
    cin >> n;
    int ans = 0;
    int weight = 0;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        weight-=a;
        weight += b;
        ans = max(ans, weight);
    }
    cout << ans << "\n";
}

void solve14(){
    int n,k;
    cin >> n >> k;
    while(k){
        int cornerDigit = n % 10;
        if(cornerDigit==0) n /= 10;
        else n -= 1;
        k--;
    }
    cout << n << "\n";
}

void solve15(){
    long long k,n,w;
    cin >> k >> n >> w;
    long long totalExpenditure = 0;
    for (int banana = 1; banana <= w;banana++){
        totalExpenditure += banana * k;
    }
    int ans = totalExpenditure-n;
    ans = max(ans, 0);
    cout << ans << "\n";
}

int main(){
    int qNum = 15;
    if(qNum==1){
        solve1();
    }
    else if(qNum==2){
        solve2();
    }
    else if(qNum==3){
        solve3();
    }
    else if(qNum==4){
        solve4();
    }
    else if(qNum==5){
        solve5();
    }
    else if(qNum==6){
        solve6();
    }
    else if(qNum==7){
        solve7();
    }
    else if(qNum==8){
        solve8();
    }
    else if(qNum==9){
        solve9();
    }
    else if(qNum==10){
        solve10();
    }
    else if(qNum==11){
        solve11();
    }
    else if(qNum==12){
        solve12();
    }
    else if(qNum==13){
        solve13();
    }
    else if(qNum==14){
        solve14();
    }
    else if(qNum==15){
        solve15();
    }
}