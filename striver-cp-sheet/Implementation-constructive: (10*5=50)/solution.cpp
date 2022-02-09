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

void solve16(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while(a<=b){
        a*=3;
        b *= 2;
        ans++;
    }
    cout << ans << "\n";
}

void solve17(){
    string ans = "CHAT WITH HER!";
    string s;
    cin>>s;
    set<char> a;
    for(char i:s) a.insert(i);
    int sz = a.size();
    if (sz % 2 == 1)
        ans = "IGNORE HIM!";
    cout << ans << "\n";
}

void solve18(){
    string s;
	cin>>s;
	if(s[0]>'Z'){
		s[0] = s[0]-('a'-'A');
	}
	cout<<s<<"\n";
}

void solve19(){
    string s;
	cin>>s;
	int n = s.size();
	vector<int> a;
	int i=-1;
	while(i<n){
		string tmp = "";
		while(i+1<n && s[i+1]!='+'){
			tmp.push_back(s[i+1]);
			i++;
		}
		if(tmp.size()){
			a.push_back(stoi(tmp));
		}
		i++;
	}
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < a.size(); i++)
    {
        cout<<a[i]<<"+";
    }
    cout<<a.back()<<"\n";
}

void solve20(){
    int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;
		if(a>n || b>n){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		while(a<=n && b<=n){
			if(a>b)	b+=a;
			else a+=b;
			ans++;
		}
		cout<<ans<<"\n";
	}
}

void solve21(){
    int n;
	cin>>n;
	int ans=0;
	int curAns=0;
	int last=-1;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		if(tmp>last)	curAns++;
		else curAns=1;
		last = tmp;
		ans = max(ans,curAns);
	}
	cout<<ans<<"\n";
}

void solve22(){
    string s;
    cin>>s;
    string ans = "NO";
    for (int i = 1; i <= 5;i++){
        string tmp;
        cin >> tmp;
        if(tmp[0]==s[0] || tmp[1]==s[1]){
            ans = "YES";
        }
    }
    cout << ans << "\n";
}

void solve23(){
    int n;
	cin>>n;
	vector<int> dp{-1};
	int sum=0;
	int totalSum=0;
	for(int i=1;totalSum<=n;i++){
		sum+=i;
		totalSum+=sum;
		dp.push_back(totalSum);
	}
	int left=1,right=dp.size();
	right--;
	int ans=0;

	while(left<=right){
		int mid = left+(right-left)/2;
		int requiredCards = dp[mid];
		if(requiredCards<=n){
			ans = max(ans,mid);
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	cout<<ans<<"\n";
}

void solve24(){
    int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int ans=0;
		for(int i=1;i<=9;i++){
			int num=0;
			int d=0;
			while(true){
				d++;
				num = num*10+i;
				int valid = num<=9999;
				if(num%10 == x%10){
					valid &= (num<=x);
				}
				if(valid)ans+=d;
				else break;
			}
			if((num%10 == x%10) && num>x) break;
		}
		cout<<ans<<"\n";
	}
}

void solve25(){
    int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		int totalZero=0;
		for(char i:s){
			if(i=='0')	 totalZero++;
		}
		if(totalZero==n){
			cout<<0<<"\n";
			continue;
		}
		int leftZero=0,rightZero=0;
		for(int i=0;i<n && s[i]=='0';i++)	leftZero++;
		for(int i=n-1;i>=0 && s[i]=='0';i--)	rightZero++;
		int ans = totalZero-leftZero-rightZero;
		cout<<ans<<"\n";
	}
}

void solve26(){
    int n;
	string s;
	cin>>n>>s;
	int curLen=1;
	for(int i=0;i<s.size();i++){
		cout<<s[i];
		for(int j=1;j<=curLen;j++){
			i++;
		}
		curLen++;
	}
	cout<<"\n";
}

void solve27(){
    int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<string> a(n);
		for(int i=0;i<n;i++)	cin>>a[i];
		int ans=0;
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				if(i==n-1 && j==m-1)	continue;
				int canGoRight = j+1<=m-1 && a[i][j]=='R';
				int canGoDowm = i+1<=n-1 && a[i][j]=='D';
				if(canGoRight && a[i][j+1]=='C') a[i][j]='C';
				if(canGoDowm && a[i+1][j]=='C')	a[i][j]='C';
				if(a[i][j]!='C'){
					a[i][j]='C';
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

void solve28(){
    set<char> vowels{'A', 'O', 'Y', 'E', 'U', 'I','a','o','y','e','u','i'};
 	string s;
 	cin>>s;
 	string ans="";
 	for(char i:s){
 		if(vowels.count(i))	continue;
 		if(i<'a')	i += ('a'-'A');
 		ans.push_back('.');
 		ans.push_back(i);
 	}
 	cout<<ans<<"\n";
}

void solve29(){
    int t;
 	cin>>t;
 	while(t--){
 		int n;
 		cin>>n;
 		n*=2;
 		vector<int> a(n);
 		for(int i=0;i<n;i++)	cin>>a[i];
 		sort(a.begin(),a.end());
 		n/=2;
 		int ans = a[n] - a[n-1];
 		cout<<ans<<"\n";
 	}
}

void solve30(){
    int t;
 	cin>>t;
 	while(t--){
 		int n;
 		cin>>n;
 		multiset<int> s;
 		for(int i=1;i<=n;i++)	s.insert(i);
 		vector<pair<int,int>> ans;
 		while(s.size()>1){
 			int sm = *s.begin() , lg = *s.rbegin();
 			s.erase(s.begin());
 			s.erase(--s.end());
 			int newNum  = (sm+lg+1)/2;
 			s.insert(newNum);
 			ans.push_back({sm,lg});
 		}
 		cout<<(*s.begin())<<"\n";
 		for(pair<int,int> i:ans)	cout<<i.first<<" "<<i.second<<"\n";
 	}
}

void solve31(){
    int t;
 	cin>>t;
 	while(t--){
 		int n;
 		cin>>n;
 		multiset<int> s;
 		for(int i=1;i<=n;i++){
 			s.insert(i);
 		}
 		vector<vector<int>> ans;
 		while(s.size()>1){
 			int last = *s.rbegin() , secondLast = *(--s.rbegin());
 			s.erase(--s.end());
 			s.erase(--s.end());
 			s.insert((last+secondLast+1)/2);
 			ans.push_back({last,secondLast});
 		}
 		cout<<(*s.begin())<<"\n";
 		for(vector<int> i:ans)	cout<<i[0]<<" "<<i[1]<<"\n";
 	}
}

void solve32(){
    int n;
 	cin>>n;
 	int sum=0;
 	int w[8];
 	for(int i=1;i<=7;i++){
 		cin>>w[i];
 		sum+=w[i];
 	}
 	n%=sum;
 	if(n==0){
 		for(int i=7;i>0;i--){
 			if(w[i]!=0){
 				cout<<i<<"\n";
 				return;
 			}
 		}
 	}
 	else{
 		sum=0;
 		for(int i=1;i<=7;i++){
 			sum += w[i];
 			if(sum>=n){
 				cout<<i<<"\n";
 				return;
 			}
 		}
 	}
}

void solve33(){
    int k;
	cin>>k;
 	string s;
 	cin>>s;
 	map<char,int> cnt;
 	for(char i:s)	cnt[i]++;
 	for(auto i:cnt){
 		if(i.second%k){
 			cout<<"-1\n";
 			return;
 		}
 	}
 	string ans="";
 	for(auto i:cnt){
 		for(int j=0;j<i.second/k;j++){
 			ans.push_back(i.first);
 		}
 	}
 	for(int i=0;i<k;i++)	cout<<ans;
 	cout<<"\n";
}

void solve34(){
    int n,m;
	cin>>n>>m;
	if(m%n){
		cout<<"-1\n";
		return;
	}
	int k = m/n;
	int ans=0;
	while( k && k%2==0){
		k/=2;
		ans++;
	}
	while( k && k%3==0){
		k/=3;
		ans++;
	}
	if(k!=1){
		cout<<"-1\n";
		return;
	}
	cout<<ans<<"\n";
}

void solve35(){
    int n;
	cin>>n;
	n++;
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=2*n-1;j++){
			int ii=i,jj=j;
			if(ii>n)	ii = 2*n-1 - ii+1;
			if(jj>n)    jj = 2*n-1 - jj+1;
			int space = jj<(n-ii+1);
			if(space){
				if(j<=n) cout<<"  ";
				continue;
			}
			int num = jj+ii-1-n;
			cout<<num;
			if(j<n+ii-1){
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}

void solve36(){}
void solve37(){}
void solve38(){}
void solve39(){}
void solve40(){}
void solve41(){}
void solve42(){}
void solve43(){}
void solve44(){}
void solve45(){}
void solve46(){}
void solve47(){}
void solve48(){}
void solve49(){}
void solve50(){}



int main(){
    int qNum = 31;
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
    else if(qNum==16){
        solve16();
    }
    else if(qNum==17){
        solve17();
    }
    else if(qNum==18){
        solve18();
    }
    else if(qNum==19){
        solve19();
    }
    else if(qNum==20){
        solve20();
    }
    else if(qNum==21){
        solve21();
    }
    else if(qNum==22){
        solve22();
    }
    else if(qNum==23){
        solve23();
    }
    else if(qNum==24){
        solve24();
    }
    else if(qNum==25){
        solve25();
    }
    else if(qNum==26){
        solve26();
    }
    else if(qNum==27){
        solve27();
    }
    else if(qNum==28){
        solve28();
    }
    else if(qNum==29){
        solve29();
    }
    else if(qNum==30){
        solve30();
    }
    else if(qNum==31){
        solve31();
    }
    else if(qNum==32){
        solve32();
    }
    else if(qNum==33){
        solve33();
    }
    else if(qNum==34){
        solve34();
    }
    else if(qNum==35){
        solve35();
    }
    else if(qNum==36){
        solve36();
    }
    else if(qNum==37){
        solve37();
    }
    else if(qNum==38){
        solve38();
    }
    else if(qNum==39){
        solve39();
    }
    else if(qNum==40){
        solve40();
    }
    else if(qNum==41){
        solve41();
    }
    else if(qNum==42){
        solve42();
    }
    else if(qNum==43){
        solve43();
    }
    else if(qNum==44){
        solve44();
    }
    else if(qNum==45){
        solve45();
    }
    else if(qNum==46){
        solve46();
    }
    else if(qNum==47){
        solve47();
    }
    else if(qNum==48){
        solve48();
    }
    else if(qNum==49){
        solve49();
    }
    else if(qNum==50){
        solve50();
    }
}