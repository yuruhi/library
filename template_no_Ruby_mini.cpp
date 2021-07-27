#include<bits/stdc++.h>
constexpr long long get_MOD(){
#ifdef SET_MOD
return SET_MOD;
#else 
return 1000000007;
#endif
}
#define rep(i,n)for(int i=0;i<(n);++i)
#define FOR(i,m,n)for(int i=(m);i<(n);++i)
#define rrep(i,n)for(int i=(n)-1;i>=0;--i)
#define rfor(i,m,n)for(int i=(m);i>=(n);--i)
#define INTERNAL_CAT_IMPL(s1,s2)s1##s2
#define INTERNAL_CAT(s1,s2)INTERNAL_CAT_IMPL(s1,s2)
#ifdef __COUNTER__
#define loop(n)rep(INTERNAL_CAT(_i,__COUNTER__),n)
#else 
#define loop(n)rep(INTERNAL_CAT(_i,__COUNTER__),n)
#endif
#define unless(c)if(!(c))
#define ALL(x)(x).begin(),(x).end()
#define RALL(x)(x).rbegin(),(x).rend()
#define range_it(a,l,r)(a).begin()+(l),(a).begin()+(r)
using ll=long long;using LD=long double;using VB=std::vector<bool>;using VVB=std::vector<VB>;using VI=std::vector<int>;\
using VVI=std::vector<VI>;using VL=std::vector<ll>;using VVL=std::vector<VL>;using VS=std::vector<std::string>;using VD=\
std::vector<LD>;using PII=std::pair<int,int>;using VP=std::vector<PII>;using PLL=std::pair<ll,ll>;using VPL=std::vector<\
PLL>;template<class T>using PQ=std::priority_queue<T>;template<class T>using PQS=std::priority_queue<T,std::vector<T>,st\
d::greater<T>>;constexpr int inf=1000000000;constexpr long long inf_ll=1000000000000000000ll,MOD=get_MOD();constexpr lon\
g double PI=3.14159265358979323846,tau=PI*2,EPS=1e-12;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Scanner{template<class T,class=void>struct has_scan : std::false_type{};template<class T>struct has_scan<T,std::v\
oid_t<decltype(std::declval<T>().template scan<Scanner>())>>: std::true_type{};public:static int gc(){return getchar_unl\
ocked();}static char next_char(){char c;scan(c);return c;}template<class T>static void scan(T&v){if(has_scan<T>::value){\
v.template scan<Scanner>();}else{std::cin>>v;}}static void scan(char&v){while(std::isspace(v=gc()));}static void scan(bo\
ol&v){v=next_char()!='0';}static void scan(std::vector<bool>::reference v){bool b;scan(b);v=b;}static void scan(std::str\
ing&v){v.clear();for(char c=next_char();!std::isspace(c);c=gc())v+=c;}static void scan(int&v){v=0;bool neg=false;char c=\
next_char();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c);c=gc())v=v*10+(c-'0');if(neg)v=-v;}static void scan(long lo\
ng&v){v=0;bool neg=false;char c=next_char();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c);c=gc())v=v*10+(c-'0');if(ne\
g)v=-v;}static void scan(double&v){v=0;double dp=1;bool neg=false,after_dp=false;char c=next_char();if(c=='-'){neg=true;\
c=gc();}for(;std::isdigit(c)||c=='.';c=gc()){if(c=='.'){after_dp=true;}else if(after_dp){v+=(c-'0')*(dp*=0.1);}else{v=v*\
10+(c-'0');}}if(neg)v=-v;}static void scan(long double&v){v=0;long double dp=1;bool neg=false,after_dp=false;char c=next\
_char();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c)||c=='.';c=gc()){if(c=='.'){after_dp=true;}else if(after_dp){v+=\
(c-'0')*(dp*=0.1);}else{v=v*10+(c-'0');}}if(neg)v=-v;}template<class T,class U>static void scan(std::pair<T,U>&v){scan(v\
.first);scan(v.second);}template<class T,std::enable_if_t<!std::is_same_v<bool,T>,std::nullptr_t> =nullptr>static void s\
can(std::vector<T>&v){for(auto&e : v)scan(e);}template<class T,std::enable_if_t<std::is_same_v<bool,T>,std::nullptr_t> =\
nullptr>static void scan(std::vector<T>&v){for(auto e : v)scan(e);}private:template<std::size_t N=0,class T>static void \
scan_tuple_impl(T&v){if constexpr(N<std::tuple_size_v<T>){scan(std::get<N>(v));scan_tuple_impl<N+1>(v);}}public:template\
<class... T>static void scan(std::tuple<T...>&v){scan_tuple_impl(v);}private:struct Read2DVectorHelper{std::size_t h,w;R\
ead2DVectorHelper(std::size_t _h,std::size_t _w): h(_h),w(_w){}template<class T>operator std::vector<std::vector<T>>(){s\
td::vector vector(h,std::vector<T>(w));scan(vector);return vector;}};struct ReadVectorHelper{std::size_t n;ReadVectorHel\
per(std::size_t _n): n(_n){}template<class T>operator std::vector<T>(){std::vector<T>vector(n);scan(vector);return vecto\
r;}auto operator[](std::size_t m){return Read2DVectorHelper(n,m);}};public:template<class T>T read()const{T result;scan(\
result);return result;}template<class T>auto read(std::size_t n)const{std::vector<T>result(n);scan(result);return result\
;}template<class T>auto read(std::size_t h,std::size_t w)const{std::vector result(h,std::vector<T>(w));scan(result);retu\
rn result;}std::string read_line()const{std::string v;for(char c=gc();c!='\n'&&c!='\0';c=gc())v+=c;return v;}template<cl\
ass T>operator T()const{return read<T>();}int operator--(int)const{return read<int>()-1;}auto operator[](std::size_t n)c\
onst{return ReadVectorHelper(n);}auto operator[](const std::pair<std::size_t,std::size_t>&nm)const{return Read2DVectorHe\
lper(nm.first,nm.second);}void operator()()const{}template<class H,class... T>void operator()(H&&h,T&&... t)const{scan(h\
);operator()(std::forward<T>(t)...);}private:template<template<class...>class,class...>struct Column;template<template<c\
lass...>class V,class Head,class... Tail>struct Column<V,Head,Tail...>{template<class... Args>using vec=V<std::vector<He\
ad>,Args...>;using type=typename Column<vec,Tail...>::type;};template<template<class...>class V>struct Column<V>{using t\
ype=V<>;};template<class... T>using column_t=typename Column<std::tuple,T...>::type;template<std::size_t N=0,class T>voi\
d column_impl(T&t)const{if constexpr(N<std::tuple_size_v<T>){auto&vec=std::get<N>(t);using V=typename std::remove_refere\
nce_t<decltype(vec)>::value_type;vec.push_back(read<V>());column_impl<N+1>(t);}}public:template<class... T>auto column(s\
td::size_t h)const{column_t<T...>result;while(h--)column_impl(result);return result;}}in;
#define inputs(T,...)T __VA_ARGS__;in(__VA_ARGS__)
#define ini(...)inputs(int,__VA_ARGS__)
#define inl(...)inputs(long long,__VA_ARGS__)
#define ins(...)inputs(std::string,__VA_ARGS__)
class Printer{public:struct BoolString{std::string_view t,f;BoolString(std::string_view _t,std::string_view _f): t(_t),\
f(_f){}};struct Separator{std::string_view div,sep,last;Separator(std::string_view _div,std::string_view _sep,std::strin\
g_view _last): div(_div),sep(_sep),last(_last){}};inline static const BoolString Yes{"Yes","No"},yes{"yes","no"},YES{"YE\
S","NO"},Int{"1","0"},Possible{"Possible","Impossible"};inline static const Separator space{" "," ","\n"},no_space{"",""\
,"\n"},endl{"\n","\n","\n"},comma{",",",","\n"},no_endl{" "," ",""},sep_endl{" ","\n","\n"};BoolString bool_str{Yes};Sep\
arator separator{space};private:template<class T,class=void>struct has_print : std::false_type{};template<class T>struct\
 has_print<T,std::void_t<decltype(std::declval<T>().print(std::declval<Printer>()))>>: std::true_type{};public:void prin\
t(int v)const{char buf[12]{};if(auto [ptr,e]=std::to_chars(std::begin(buf),std::end(buf),v);e==std::errc{}){print(std::s\
tring_view(buf,ptr-buf));}else{assert(false);}}void print(long long v)const{char buf[21]{};if(auto [ptr,e]=std::to_chars\
(std::begin(buf),std::end(buf),v);e==std::errc{}){print(std::string_view(buf,ptr-buf));}else{assert(false);}}void print(\
bool v)const{print(v ? bool_str.t : bool_str.f);}void print(std::vector<bool>::reference v)const{print(v ? bool_str.t : \
bool_str.f);}void print(char v)const{putchar_unlocked(v);}void print(std::string_view v)const{fwrite_unlocked(v.data(),s\
izeof(std::string_view::value_type),v.size(),stdout);}void print(double v)const{std::printf("%.20f",v);}void print(long \
double v)const{std::printf("%.20Lf",v);}template<class T,std::enable_if_t<has_print<T>::value,std::nullptr_t> =nullptr>v\
oid print(const T&v)const{v.print(*this);}template<class T,std::enable_if_t<!has_print<T>::value,std::nullptr_t> =nullpt\
r>void print(const T&v)const{std::cout<<v;}template<class T,class U>void print(const std::pair<T,U>&v)const{print(v.firs\
t);print(separator.div);print(v.second);}template<class T>void print(const std::optional<T>&v)const{print(*v);}template<\
class InputIterater>void print_range(const InputIterater&begin,const InputIterater&end)const{for(InputIterater i=begin;i\
!=end;++i){if(i!=begin)print(separator.sep);print(*i);}}template<class T>void print(const std::vector<T>&v)const{print_r\
ange(v.begin(),v.end());}template<class T,std::size_t N>void print(const std::array<T,N>&v)const{print_range(v.begin(),v\
.end());}template<class T>void print(const std::vector<std::vector<T>>&v)const{for(std::size_t i=0;i<v.size();++i){if(i)\
print(separator.last);print(v[i]);}}Printer()=default;Printer(const BoolString&_bool_str,const Separator&_separator): bo\
ol_str(_bool_str),separator(_separator){}Printer&operator()(){print(separator.last);return*this;}template<class Head>Pri\
nter&operator()(Head&&head){print(head);print(separator.last);return*this;}template<class Head,class... Tail>Printer&ope\
rator()(Head&&head,Tail&&... tail){print(head);print(separator.sep);return operator()(std::forward<Tail>(tail)...);}temp\
late<class... Args>Printer&flag(bool f,Args&&... args){if(f){return operator()(std::forward<Args>(args)...);}else{return\
*this;}}template<class InputIterator>Printer&range(const InputIterator&begin,const InputIterator&end){print_range(begin,\
end);print(separator.last);return*this;}template<class Container>Printer&range(const Container&a){range(a.begin(),a.end(\
));return*this;}template<class... T>void exit(T&&... t){operator()(std::forward<T>(t)...);std::exit(EXIT_SUCCESS);}Print\
er&flush(){fflush_unlocked(stdout);return*this;}Printer&set(const BoolString&_bool_str){bool_str=_bool_str;return*this;}\
Printer&set(const Separator&_separator){separator=_separator;return*this;}Printer&set(std::string_view t,std::string_vie\
w f){bool_str=BoolString(t,f);return*this;}}out;
template<class T=long long>constexpr T TEN(std::size_t n){T result=1;for(std::size_t i=0;i<n;++i)result*=10;return resu\
lt;}template<class T,class U,std::enable_if_t<std::is_integral_v<T>&&std::is_integral_v<U>,std::nullptr_t> =nullptr>cons\
texpr auto div_ceil(T n,U m){return(n+m-1)/m;}template<class T,class U>constexpr auto div_ceil2(T n,U m){return div_ceil\
(n,m)*m;}template<class T>constexpr T triangle(T n){return(n&1)?(n+1)/2*n : n/2*(n+1);}template<class T>constexpr T nC2(\
T n){return(n&1)?(n-1)/2*n : n/2*(n-1);}template<class T,class U>constexpr auto middle(const T&l,const U&r){return l+(r-\
l)/2;}template<class T,class U,class V>constexpr bool in_range(const T&v,const U&lower,const V&upper){return lower<=v&&v\
<upper;}template<class T,std::enable_if_t<std::is_integral_v<T>,std::nullptr_t> =nullptr>constexpr bool is_square(T n){T\
 s=std::sqrt(n);return s*s==n||(s+1)*(s+1)==n;}template<class T=long long>constexpr T BIT(int b){return T(1)<<b;}templat\
e<class T>constexpr int BIT(T x,int i){return(x&(T(1)<<i))? 1 : 0;}template<class T>constexpr int Sgn(T x){return(0<x)-(\
0>x);}template<class T>bool is_leap(T year){return!(year%4)&&(year%100||!(year%400));}template<class T,class U,std::enab\
le_if_t<std::is_integral_v<U>,std::nullptr_t> =nullptr>constexpr T Pow(T a,U n){assert(n>=0);T result=1;while(n>0){if(n&\
1){result*=a;n--;}else{a*=a;n>>=1;}}return result;}template<class T,class U,std::enable_if_t<std::is_integral_v<U>,std::\
nullptr_t> =nullptr>constexpr T Powmod(T a,U n,T mod){assert(n>=0);if(a>mod)a%=mod;T result=1;while(n>0){if(n&1){result=\
result*a%mod;n--;}else{a=a*a%mod;n>>=1;}}return result;}template<class T>bool chmax(T&a,const T&b){return a<b ? a=b,true\
 : false;}template<class T>bool chmin(T&a,const T&b){return a>b ? a=b,true : false;}template<class T>int sz(const T&v){r\
eturn v.size();}template<class T,class U>int lower_index(const T&a,const U&v){return std::lower_bound(a.begin(),a.end(),\
v)-a.begin();}template<class T,class U,class F>int lower_index(const T&a,const U&v,const F&f){return std::lower_bound(a.\
begin(),a.end(),v,f)-a.begin();}template<class T,class U>int upper_index(const T&a,const U&v){return std::upper_bound(a.\
begin(),a.end(),v)-a.begin();}template<class T,class U,class F>int upper_index(const T&a,const U&v,const F&f){return std\
::upper_bound(a.begin(),a.end(),v,f)-a.begin();}template<class T,class U=typename T::value_type>U Gcdv(const T&v){return\
 std::accumulate(std::next(v.begin()),v.end(),U(*v.begin()),std::gcd<U,U>);}template<class T,class U=typename T::value_t\
ype>U Lcmv(const T&v){return std::accumulate(std::next(v.begin()),v.end(),U(*v.begin()),std::lcm<U,U>);}template<class T\
>T&Concat(T&v,const T&vec){v.insert(v.end(),vec.begin(),vec.end());return v;}namespace internal{template<class T,std::si\
ze_t N>auto make_vector(std::vector<int>&sizes,const T&init){if constexpr(N==1){return std::vector(sizes[0],init);}else{\
int size=sizes[N-1];sizes.pop_back();return std::vector(size,make_vector<T,N-1>(sizes,init));}}}template<class T,std::si\
ze_t N>auto make_vector(const int(&sizes)[N],const T&init=T()){std::vector s(std::rbegin(sizes),std::rend(sizes));return\
 internal::make_vector<T,N>(s,init);}template<class F>struct rec_lambda{F f;rec_lambda(F&&f_): f(std::forward<F>(f_)){}t\
emplate<class... Args>auto operator()(Args&&... args)const{return f(*this,std::forward<Args>(args)...);}};namespace lamb\
da{auto char_to_int=[](char c){return c-'0';};auto lower_to_int=[](char c){return c-'a';};auto upper_to_int=[](char c){r\
eturn c-'A';};auto int_to_char=[](int i)->char{return '0'+i;};auto int_to_lower=[](int i)->char{return 'a'+i;};auto int_\
to_upper=[](int i)->char{return 'A'+i;};auto is_odd=[](auto n){return n%2==1;};auto is_even=[](auto n){return n%2==0;};a\
uto is_positive=[](auto n){return n>0;};auto is_negative=[](auto n){return n<0;};auto increment=[](auto n){return++n;};a\
uto decrement=[](auto n){return--n;};auto self=[](const auto&n){return n;};auto first=[](const auto&n){return n.first;};\
auto second=[](const auto&n){return n.second;};template<class T>auto cast(){return [](const auto&n){return static_cast<T\
>(n);};};template<class T>auto equal_to(const T&x){return [x](auto y){return x==y;};}template<std::size_t I>auto get(){r\
eturn [](const auto&n){return std::get<I>(n);};}template<class F>auto cmp(F&&f){return [f](const auto&a,const auto&b){re\
turn f(a)<f(b);};}}
#if __has_include(<library/dump.hpp>)
#include<library/dump.hpp>
#define LOCAL
#else 
#define dump(...)((void)0)
#define dump2(...)((void)0)
#endif
template<class T>constexpr T oj_local(const T&oj,const T&local){
#ifndef LOCAL
return oj;
#else 
return local;
#endif
}