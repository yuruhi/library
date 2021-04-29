#include<bits/stdc++.h>
#include"./Utility/get_MOD.cpp"
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
using ll=long long;using LD=long double;using VB=std::vector<bool>;using VVB=std::vector<VB>;using VI=std::vector<int>;u\
sing VVI=std::vector<VI>;using VL=std::vector<ll>;using VVL=std::vector<VL>;using VS=std::vector<std::string>;using VD=s\
td::vector<LD>;using PII=std::pair<int,int>;using VP=std::vector<PII>;using PLL=std::pair<ll,ll>;using VPL=std::vector<P\
LL>;template<class T>using PQ=std::priority_queue<T>;template<class T>using PQS=std::priority_queue<T,std::vector<T>,std\
::greater<T>>;constexpr int inf=1000000000;constexpr long long inf_ll=1000000000000000000ll,MOD=get_MOD();constexpr long\
 double PI=3.14159265358979323846,tau=PI*2,EPS=1e-12;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Scanner{template<class T,class=void>struct has_scan:std::false_type{};template<class T>struct has_scan<T,std::void\
_t<decltype(std::declval<T>().template scan<Scanner>())>>: std::true_type{};public:static int gc(){return getchar_unlock\
ed();}static char next_char(){char c;scan(c);return c;}template<class T>static void scan(T&v){if(has_scan<T>::value){v.t\
emplate scan<Scanner>();}else{std::cin>>v;}}static void scan(char&v){while(std::isspace(v=gc()));}static void scan(bool&\
v){v=next_char()!='0';}static void scan(std::vector<bool>::reference v){bool b;scan(b);v=b;}static void scan(std::string\
&v){v.clear();for(char c=next_char();!std::isspace(c);c=gc())v+=c;}static void scan(int&v){v=0;bool neg=false;char c=nex\
t_char();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c);c=gc())v=v*10+(c-'0');if(neg)v=-v;}static void scan(long long&\
v){v=0;bool neg=false;char c=next_char();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c);c=gc())v=v*10+(c-'0');if(neg)v\
=-v;}static void scan(double&v){v=0;double dp=1;bool neg=false,after_dp=false;char c=next_char();if(c=='-'){neg=true;c=g\
c();}for(;std::isdigit(c)||c=='.';c=gc()){if(c=='.'){after_dp=true;}else if(after_dp){v+=(c-'0')*(dp*=0.1);}else{v=v*10+\
(c-'0');}}if(neg)v=-v;}static void scan(long double&v){v=0;long double dp=1;bool neg=false,after_dp=false;char c=next_ch\
ar();if(c=='-'){neg=true;c=gc();}for(;std::isdigit(c)||c=='.';c=gc()){if(c=='.'){after_dp=true;}else if(after_dp){v+=(c-\
'0')*(dp*=0.1);}else{v=v*10+(c-'0');}}if(neg)v=-v;}template<class T,class U>static void scan(std::pair<T,U>&v){scan(v.fi\
rst);scan(v.second);}template<class T,std::enable_if_t<!std::is_same_v<bool,T>,std::nullptr_t> =nullptr>static void scan\
(std::vector<T>&v){for(auto&e:v)scan(e);}template<class T,std::enable_if_t<std::is_same_v<bool,T>,std::nullptr_t> =nullp\
tr>static void scan(std::vector<T>&v){for(auto e:v)scan(e);}private:template<std::size_t N=0,class T>static void scan_tu\
ple_impl(T&v){if constexpr(N<std::tuple_size_v<T>){scan(std::get<N>(v));scan_tuple_impl<N+1>(v);}}public:template<class.\
.. T>static void scan(std::tuple<T...>&v){scan_tuple_impl(v);}private:struct Read2DVectorHelper{std::size_t h,w;Read2DVe\
ctorHelper(std::size_t _h,std::size_t _w): h(_h),w(_w){}template<class T>operator std::vector<std::vector<T>>(){std::vec\
tor vector(h,std::vector<T>(w));scan(vector);return vector;}};struct ReadVectorHelper{std::size_t n;ReadVectorHelper(std\
::size_t _n): n(_n){}template<class T>operator std::vector<T>(){std::vector<T>vector(n);scan(vector);return vector;}auto\
 operator[](std::size_t m){return Read2DVectorHelper(n,m);}};public:template<class T>T read()const{T result;scan(result)\
;return result;}template<class T>auto read(std::size_t n)const{std::vector<T>result(n);scan(result);return result;}templ\
ate<class T>auto read(std::size_t h,std::size_t w)const{std::vector result(h,std::vector<T>(w));scan(result);return resu\
lt;}std::string read_line()const{std::string v;for(char c=gc();c!='\n'&&c!='\0';c=gc())v+=c;return v;}template<class T>o\
perator T()const{return read<T>();}int operator--(int)const{return read<int>()-1;}auto operator[](std::size_t n)const{re\
turn ReadVectorHelper(n);}auto operator[](const std::pair<std::size_t,std::size_t>&nm)const{return Read2DVectorHelper(nm\
.first,nm.second);}void operator()()const{}template<class H,class... T>void operator()(H&&h,T&&... t)const{scan(h);opera\
tor()(std::forward<T>(t)...);}private:template<template<class...>class,class...>struct Column;template<template<class...\
>class V,class Head,class... Tail>struct Column<V,Head,Tail...>{template<class... Args>using vec=V<std::vector<Head>,Arg\
s...>;using type=typename Column<vec,Tail...>::type;};template<template<class...>class V>struct Column<V>{using type=V<>\
;};template<class... T>using column_t=typename Column<std::tuple,T...>::type;template<std::size_t N=0,class T>void colum\
n_impl(T&t)const{if constexpr(N<std::tuple_size_v<T>){auto&vec=std::get<N>(t);using V=typename std::remove_reference_t<d\
ecltype(vec)>::value_type;vec.push_back(read<V>());column_impl<N+1>(t);}}public:template<class... T>auto column(std::siz\
e_t h)const{column_t<T...>result;while(h--)column_impl(result);return result;}}in;
#define inputs(T,...)\
T __VA_ARGS__;\in(__VA_ARGS__)
#define ini(...)inputs(int,__VA_ARGS__)
#define inl(...)inputs(long long,__VA_ARGS__)
#define ins(...)inputs(std::string,__VA_ARGS__)
class Printer{public:struct BoolString{std::string_view t,f;BoolString(std::string_view _t,std::string_view _f): t(_t),f\
(_f){}};struct Separator{std::string_view div,sep,last;Separator(std::string_view _div,std::string_view _sep,std::string\
_view _last): div(_div),sep(_sep),last(_last){}};inline static const BoolString Yes{"Yes","No"},yes{"yes","no"},YES{"YES\
","NO"},Int{"1","0"},Possible{"Possible","Impossible"};inline static const Separator space{" "," ","\n"},no_space{"","",\
"\n"},endl{"\n","\n","\n"},comma{",",",","\n"},no_endl{" "," ",""},sep_endl{" ","\n","\n"};BoolString bool_str{Yes};Sepa\
rator separator{space};private:template<class T,class=void>struct has_print:std::false_type{};template<class T>struct ha\
s_print<T,std::void_t<decltype(std::declval<T>().print(std::declval<Printer>()))>>: std::true_type{};public:void print(i\
nt v)const{char buf[12]{};if(auto [ptr,e]=std::to_chars(std::begin(buf),std::end(buf),v);e==std::errc{}){print(std::stri\
ng_view(buf,ptr-buf));}else{assert(false);}}void print(long long v)const{char buf[21]{};if(auto [ptr,e]=std::to_chars(st\
d::begin(buf),std::end(buf),v);e==std::errc{}){print(std::string_view(buf,ptr-buf));}else{assert(false);}}void print(boo\
l v)const{print(v?bool_str.t:bool_str.f);}void print(std::vector<bool>::reference v)const{print(v?bool_str.t:bool_str.f)\
;}void print(char v)const{putchar_unlocked(v);}void print(std::string_view v)const{fwrite_unlocked(v.data(),sizeof(std::\
string_view::value_type),v.size(),stdout);}void print(double v)const{std::printf("%.20f",v);}void print(long double v)co\
nst{std::printf("%.20Lf",v);}template<class T,std::enable_if_t<has_print<T>::value,std::nullptr_t> =nullptr>void print(c\
onst T&v)const{v.print(*this);}template<class T,std::enable_if_t<!has_print<T>::value,std::nullptr_t> =nullptr>void prin\
t(const T&v)const{std::cout<<v;}template<class T,class U>void print(const std::pair<T,U>&v)const{print(v.first);print(se\
parator.div);print(v.second);}template<class T>void print(const std::optional<T>&v)const{print(*v);}template<class Input\
Iterater>void print_range(const InputIterater&begin,const InputIterater&end)const{for(InputIterater i=begin;i!=end;++i){\
if(i!=begin)print(separator.sep);print(*i);}}template<class T>void print(const std::vector<T>&v)const{print_range(v.begi\
n(),v.end());}template<class T,std::size_t N>void print(const std::array<T,N>&v)const{print_range(v.begin(),v.end());}te\
mplate<class T>void print(const std::vector<std::vector<T>>&v)const{for(std::size_t i=0;i<v.size();++i){if(i)print(separ\
ator.last);print(v[i]);}}Printer()=default;Printer(const BoolString&_bool_str,const Separator&_separator): bool_str(_boo\
l_str),separator(_separator){}Printer&operator()(){print(separator.last);return*this;}template<class Head>Printer&operat\
or()(Head&&head){print(head);print(separator.last);return*this;}template<class Head,class... Tail>Printer&operator()(Hea\
d&&head,Tail&&... tail){print(head);print(separator.sep);return operator()(std::forward<Tail>(tail)...);}template<class.\
.. Args>Printer&flag(bool f,Args&&... args){if(f){return operator()(std::forward<Args>(args)...);}else{return*this;}}tem\
plate<class InputIterator>Printer&range(const InputIterator&begin,const InputIterator&end){print_range(begin,end);print(\
separator.last);return*this;}template<class Container>Printer&range(const Container&a){range(a.begin(),a.end());return*t\
his;}template<class... T>void exit(T&&... t){operator()(std::forward<T>(t)...);std::exit(EXIT_SUCCESS);}Printer&flush(){\
fflush_unlocked(stdout);return*this;}Printer&set(const BoolString&_bool_str){bool_str=_bool_str;return*this;}Printer&set\
(const Separator&_separator){separator=_separator;return*this;}Printer&set(std::string_view t,std::string_view f){bool_s\
tr=BoolString(t,f);return*this;}}out;template<class T>class step_iterator{public:using value_type=T;using difference_typ\
e=T;using iterator_category=std::random_access_iterator_tag;using reference=T&;using pointer=T*;private:value_type start\
_m,size_m,step_m,index_m;public:constexpr step_iterator(): start_m(value_type()),size_m(value_type()),step_m(value_type(\
)),index_m(0){}constexpr step_iterator(value_type _start,value_type _size,value_type _step): start_m(_start),size_m(_siz\
e),step_m(_step),index_m(0){}value_type operator*()const noexcept{return value();}step_iterator&operator++()noexcept{++i\
ndex_m;return*this;}step_iterator&operator++(int)noexcept{auto tmp=*this;++*this;return tmp;}step_iterator&operator--()n\
oexcept{--index_m;return*this;}step_iterator&operator--(int)noexcept{auto tmp=*this;--*this;return tmp;}step_iterator&op\
erator+=(difference_type n){index_m+=n;return*this;}step_iterator operator+(difference_type n)const{return step_iterator\
(*this)+=n;}friend step_iterator operator+(difference_type n,step_iterator i){return i+n;}step_iterator&operator-=(diffe\
rence_type n){index_m-=n;return*this;}step_iterator operator-(difference_type n)const{return step_iterator(*this)-=n;}fr\
iend step_iterator operator-(difference_type n,step_iterator i){return i-n;}difference_type operator-(const step_iterato\
r&other)const{assert(start_m==other.start_m);assert(size_m==other.size_m);assert(step_m==other.step_m);return index_m-ot\
her.index_m;}bool operator==(const step_iterator&other)const noexcept{return value()==other.value();}bool operator!=(con\
st step_iterator&other)const noexcept{return value()!=other.value();}bool operator<(const step_iterator&other)const noex\
cept{return value()<other.value();}bool operator<=(const step_iterator&other)const noexcept{return value()<=other.value(\
);}bool operator>(const step_iterator&other)const noexcept{return value()>other.value();}bool operator>=(const step_iter\
ator&other)const noexcept{return value()>=other.value();}constexpr value_type value()const noexcept{return start_m+step_\
m*index_m;}};template<class T>class Step{public:using value_type=T;using iterator=step_iterator<value_type>;private:valu\
e_type start_m,size_m,step_m;public:constexpr Step(value_type _start,value_type _size,value_type _step): start_m(_start)\
,size_m(std::max<value_type>(0,_size)),step_m(_step){}constexpr iterator begin()const{return iterator(start_m,size_m,ste\
p_m);}constexpr iterator end()const{return iterator(start_m,size_m,step_m)+size_m;}constexpr value_type start()const{ret\
urn start_m;}constexpr value_type size()const{return size_m;}constexpr value_type step()const{return step_m;}constexpr v\
alue_type sum()const{return start()*size()+step()*(size()*(size()-1)/2);}operator std::vector<value_type>()const{return \
to_a();}auto to_a()const{std::vector<value_type>result;result.reserve(size());for(auto i :*this){result.push_back(i);}re\
turn result;}};template<class T>constexpr auto upto(T from,T to,bool exclusive=true){return Step<T>(from,to-from+exclusi\
ve,1);}template<class T>constexpr auto downto(T from,T to,bool exclusive=true){return Step<T>(from,from-to+exclusive,-1)\
;}template<class T>constexpr auto times(T n,bool exclusive=false){return Step<T>(0,n+static_cast<T>(exclusive),1);}templ\
ate<class F>struct Callable{F func;Callable(const F&f): func(f){}};template<class T,class F>auto operator|(const T&v,con\
st Callable<F>&c){return c.func(v);}struct Sort_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){\
std::sort(std::begin(v),std::end(v),f);return v;});}template<class T>friend auto operator|(T v,[[maybe_unused]] const So\
rt_impl&c){std::sort(std::begin(v),std::end(v));return v;}}Sort;struct SortBy_impl{template<class F>auto operator()(F&&f\
){return Callable([&](auto v){std::sort(std::begin(v),std::end(v),[&](const auto&i,const auto&j){return f(i)<f(j);});ret\
urn v;});}}SortBy;struct RSort_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){std::sort(rbegin(\
v),rend(v),f);return v;});}template<class T>friend auto operator|(T v,[[maybe_unused]] const RSort_impl&c){std::sort(rbe\
gin(v),rend(v));return v;}}RSort;struct RSortBy_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){\
std::sort(std::begin(v),std::end(v),[&](const auto&i,const auto&j){return f(i)>f(j);});return v;});}}RSortBy;struct Reve\
rse_impl{template<class T>friend auto operator|(T v,const Reverse_impl&c){std::reverse(std::begin(v),std::end(v));return\
 v;}}Reverse;struct Unique_impl{template<class T>friend auto operator|(T v,const Unique_impl&c){v.erase(std::unique(std:\
:begin(v),std::end(v),std::end(v)));return v;}template<class T,class F>auto operator()(F&&f){return Callable([&](auto v)\
{v.erase(std::unique(std::begin(v),std::end(v),f),std::end(v));return v;});}}Unique;struct Uniq_impl{template<class T>fr\
iend auto operator|(T v,const Uniq_impl&c){std::sort(std::begin(v),std::end(v));v.erase(std::unique(std::begin(v),std::e\
nd(v)),std::end(v));return v;}}Uniq;struct Rotate_impl{auto operator()(int&&left){return Callable([&](auto v){int s=stat\
ic_cast<int>(std::size(v));assert(-s<=left&&left<=s);if(0<=left){std::rotate(std::begin(v),std::begin(v)+left,std::end(v\
));}else{std::rotate(std::begin(v),std::end(v)+left,std::end(v));}return v;});}}Rotate;struct Max_impl{template<class F>\
auto operator()(F&&f){return Callable([&](auto v){return*std::max_element(std::begin(v),std::end(v),f);});}template<clas\
s T>friend auto operator|(T v,const Max_impl&c){return*std::max_element(std::begin(v),std::end(v));}}Max;struct Min_impl\
{template<class F>auto operator()(F&&f){return Callable([&](auto v){return*std::min_element(std::begin(v),std::end(v),f)\
;});}template<class T>friend auto operator|(T v,const Min_impl&c){return*std::min_element(std::begin(v),std::end(v));}}M\
in;struct MaxPos_impl{template<class T>friend auto operator|(T v,const MaxPos_impl&c){return std::max_element(std::begin\
(v),std::end(v))-std::begin(v);}}MaxPos;struct MinPos_impl{template<class T>friend auto operator|(T v,const MinPos_impl&\
c){return std::min_element(std::begin(v),std::end(v))-std::begin(v);}}MinPos;struct MaxBy_impl{template<class F>auto ope\
rator()(F&&f){return Callable([&](auto v){auto max_it=std::begin(v);auto max_val=f(*max_it);for(auto it=std::next(std::b\
egin(v));it!=std::end(v);++it){if(auto val=f(*it);max_val<val){max_it=it;max_val=val;}}return*max_it;});}}MaxBy;struct M\
inBy_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){auto min_it=std::begin(v);auto min_val=f(*m\
in_it);for(auto it=std::next(std::begin(v));it!=std::end(v);++it){if(auto val=f(*it);min_val>val){min_it=it;min_val=val;\
}}return*min_it;});}}MinBy;struct MaxOf_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){auto max\
_val=f(*std::begin(v));for(auto it=std::next(std::begin(v));it!=std::end(v);++it){if(auto val=f(*it);max_val<val){max_va\
l=val;}}return max_val;});}}MaxOf;struct MinOf_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){a\
uto min_val=f(*std::begin(v));for(auto it=std::next(std::begin(v));it!=std::end(v);++it){if(auto val=f(*it);min_val>val)\
{min_val=val;}}return min_val;});}}MinOf;struct Count_impl{template<class V>auto operator()(const V&val){return Callable\
([&](auto v){return std::count(std::begin(v),std::end(v),val);});}}Count;struct CountIf_impl{template<class F>auto opera\
tor()(const F&f){return Callable([&](auto v){return std::count_if(std::begin(v),std::end(v),f);});}}CountIf;struct Index\
_impl{template<class V>auto operator()(const V&val){return Callable([&](auto v)->std::optional<int>{auto result=std::fin\
d(std::begin(v),std::end(v),val);return result!=std::end(v)? std::optional(result-std::begin(v)): std::nullopt;});}templ\
ate<class V>auto operator()(const V&val,std::size_t i){return Callable([&](auto v)->std::optional<int>{auto result=std::\
find(std::next(std::begin(v),i),std::end(v),val);return result!=std::end(v)? std::optional(result-std::begin(v)): std::n\
ullopt;});}}Index;struct IndexIf_impl{template<class F>auto operator()(const F&f){return Callable([&](auto v)->std::opti\
onal<int>{auto result=std::find_if(std::begin(v),std::end(v),f);return result!=std::end(v)? std::optional(result-std::be\
gin(v)): std::nullopt;});}}IndexIf;struct FindIf_impl{template<class F>auto operator()(const F&f){return Callable([&](au\
to v)->std::optional<typename decltype(v)::value_type>{auto result=std::find_if(std::begin(v),std::end(v),f);return resu\
lt!=std::end(v)? std::optional(*result): std::nullopt;});}}FindIf;struct Sum_impl{template<class F>auto operator()(F&&f)\
{return Callable([&](auto v){return std::accumulate(std::next(std::begin(v)),std::end(v),f(*std::begin(v)),[&](const aut\
o&a,const auto&b){return a+f(b);});});}template<class T>friend auto operator|(T v,[[maybe_unused]] const Sum_impl&c){ret\
urn std::accumulate(std::begin(v),std::end(v),typename T::value_type{});}}Sum;struct Includes{template<class V>auto oper\
ator()(const V&val){return Callable([&](auto v){return std::find(std::begin(v),std::end(v),val)!=std::end(v);});}}Includ\
es;struct IncludesIf_impl{template<class F>auto operator()(const F&f){return Callable([&](auto v){return std::find_if(st\
d::begin(v),std::end(v),f)!=std::end(v);});}}IncludesIf;struct RemoveIf_impl{template<class F>auto operator()(const F&f)\
{return Callable([&](auto v){v.erase(std::remove_if(std::begin(v),std::end(v),f),std::end(v));return v;});}}RemoveIf;str\
uct Each_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){for(const auto&i:v){f(i);}});}}Each;str\
uct EachConsPair_impl{template<class T,class value_type=typename T::value_type>friend auto operator|(const T&v,EachConsP\
air_impl&c){std::vector<std::pair<value_type,value_type>>result;if(std::size(v)>=2){result.reserve(std::size(v)-1);for(s\
td::size_t i=0;i<std::size(v)-1;++i){result.emplace_back(v[i],v[i+1]);}}return result;}}EachConsPair;struct Select_impl{\
template<class F>auto operator()(F&&f){return Callable([&](auto v){using value_type=typename decltype(v)::value_type;std\
::vector<value_type>result;for(const auto&i:v){if(f(i))result.push_back(i);}return result;});}}Select;struct Map_impl{te\
mplate<class F>auto operator()(F&&f){return Callable([&](auto v){using result_type=std::invoke_result_t<F,typename declt\
ype(v)::value_type>;std::vector<result_type>result;result.reserve(std::size(v));for(const auto&i:v){result.push_back(f(i\
));}return result;});}}Map;struct Indexed_impl{template<class T>friend auto operator|(const T&v,Indexed_impl&c){using va\
lue_type=typename T::value_type;std::vector<std::pair<value_type,int>>result;result.reserve(std::size(v));int index=0;fo\
r(const auto&i:v){result.emplace_back(i,index++);}return result;}}Indexed;struct AllOf_impl{template<class F>auto operat\
or()(F&&f){return Callable([&](auto v){for(const auto&i:v){if(!f(i))return false;}return true;});}}AllOf;struct AnyOf_im\
pl{template<class F>auto operator()(F&&f){return Callable([&](auto v){for(const auto&i:v){if(f(i))return true;}return fa\
lse;});}}AnyOf;struct NoneOf_impl{template<class F>auto operator()(F&&f){return Callable([&](auto v){for(const auto&i:v)\
{if(f(i))return false;}return true;});}}NoneOf;struct Tally_impl{auto operator()(std::size_t max_val){return Callable([&\
](auto v){std::vector<std::size_t>result(max_val);for(const auto&i:v){result[static_cast<std::size_t>(i)]++;}return resu\
lt;});}template<class T,class value_type=typename T::value_type>friend auto operator|(const T&v,Tally_impl&c){std::map<v\
alue_type,std::size_t>result;for(const auto&i:v){result[i]++;}return result;}}Tally;struct Reduce_impl{template<class T,\
class F>auto operator()(T memo,F f){return Callable([memo,f](auto v){auto acc=memo;for(auto i:v){acc=f(acc,i);}return ac\
c;});}}Reduce;struct Join_impl{auto operator()(std::string separater){return Callable([&](auto v){std::string result;boo\
l first=true;for(const auto&i:v){if(!std::exchange(first,false)){result+=separater;}result+=std::to_string(i);}return re\
sult;});}template<class T>friend auto operator|(const T&v,Join_impl&c){return v|c("");}}Join;struct At_impl{auto operato\
r()(std::size_t l,std::size_t r){return Callable([l,r](auto v){return decltype(v)(std::begin(v)+l,std::begin(v)+r);});}}\
At;struct Slice_impl{auto operator()(std::size_t i,std::size_t cnt){return Callable([i,cnt](auto v){return decltype(v)(s\
td::begin(v)+i,std::begin(v)+i+cnt);});}}Slice;struct Transpose_impl{template<class T>friend auto operator|(const std::v\
ector<std::vector<T>>&v,Transpose_impl&c){std::size_t h=v.size(),w=v.front().size();std::vector result(w,std::vector<T>(\
h));for(std::size_t i=0;i<h;++i){assert(v[i].size()==w);for(std::size_t j=0;j<w;++j){result[j][i]=v[i][j];}}return resul\
t;}}Transpose;template<class T>auto operator*(const std::vector<T>&a,std::size_t n){T result;for(std::size_t i=0;i<n;++i\
){result.insert(result.end(),a.begin(),a.end());}return result;}auto operator*(std::string a,std::size_t n){std::string \
result;for(std::size_t i=0;i<n;++i){result+=a;}return result;}namespace internal{template<class T,class U,class=void>str\
uct has_push_back:std::false_type{};template<class T,class U>struct has_push_back<T,U,std::void_t<decltype(std::declval<\
T>().push_back(std::declval<U>()))>>: std::true_type{};}template<class Container,class T,std::enable_if_t<internal::has_\
push_back<Container,T>::value,std::nullptr_t> =nullptr>auto&operator<<(Container&continer,const T&val){continer.push_bac\
k(val);return continer;}template<class Container,class T,std::enable_if_t<internal::has_push_back<Container,T>::value,st\
d::nullptr_t> =nullptr>auto operator+(Container continer,const T&val){continer<<val;return continer;}template<class T=lo\
ng long>constexpr T TEN(std::size_t n){T result=1;for(std::size_t i=0;i<n;++i)result*=10;return result;}template<class T\
,class U,std::enable_if_t<std::is_integral_v<T>&&std::is_integral_v<U>,std::nullptr_t> =nullptr>constexpr auto div_ceil(\
T n,U m){return(n+m-1)/m;}template<class T,class U>constexpr auto div_ceil2(T n,U m){return div_ceil(n,m)*m;}template<cl\
ass T>constexpr T triangle(T n){return(n&1)?(n+1)/2*n:n/2*(n+1);}template<class T>constexpr T nC2(T n){return(n&1)?(n-1)\
/2*n:n/2*(n-1);}template<class T,class U>constexpr auto middle(const T&l,const U&r){return l+(r-l)/2;}template<class T,c\
lass U,class V>constexpr bool in_range(const T&v,const U&lower,const V&upper){return lower<=v&&v<upper;}template<class T\
,std::enable_if_t<std::is_integral_v<T>,std::nullptr_t> =nullptr>constexpr bool is_square(T n){T s=std::sqrt(n);return s\
*s==n||(s+1)*(s+1)==n;}template<class T=long long>constexpr T BIT(int b){return T(1)<<b;}template<class T>constexpr int \
BIT(T x,int i){return(x&(T(1)<<i))? 1:0;}template<class T>constexpr int Sgn(T x){return(0<x)-(0>x);}template<class T>boo\
l is_leap(T year){return!(year%4)&&(year%100||!(year%400));}template<class T,class U,std::enable_if_t<std::is_integral_v\
<U>,std::nullptr_t> =nullptr>constexpr T Pow(T a,U n){assert(n>=0);T result=1;while(n>0){if(n&1){result*=a;n--;}else{a*=\
a;n>>=1;}}return result;}template<class T,class U,std::enable_if_t<std::is_integral_v<U>,std::nullptr_t> =nullptr>conste\
xpr T Powmod(T a,U n,T mod){assert(n>=0);if(a>mod)a%=mod;T result=1;while(n>0){if(n&1){result=result*a%mod;n--;}else{a=a\
*a%mod;n>>=1;}}return result;}template<class T>bool chmax(T&a,const T&b){return a<b?a=b,true:false;}template<class T>boo\
l chmin(T&a,const T&b){return a>b?a=b,true:false;}template<class T>int sz(const T&v){return v.size();}template<class T,c\
lass U>int lower_index(const T&a,const U&v){return std::lower_bound(a.begin(),a.end(),v)-a.begin();}template<class T,cla\
ss U,class F>int lower_index(const T&a,const U&v,const F&f){return std::lower_bound(a.begin(),a.end(),v,f)-a.begin();}te\
mplate<class T,class U>int upper_index(const T&a,const U&v){return std::upper_bound(a.begin(),a.end(),v)-a.begin();}temp\
late<class T,class U,class F>int upper_index(const T&a,const U&v,const F&f){return std::upper_bound(a.begin(),a.end(),v,\
f)-a.begin();}template<class T,class U=typename T::value_type>U Gcdv(const T&v){return std::accumulate(std::next(v.begin\
()),v.end(),U(*v.begin()),std::gcd<U,U>);}template<class T,class U=typename T::value_type>U Lcmv(const T&v){return std::\
accumulate(std::next(v.begin()),v.end(),U(*v.begin()),std::lcm<U,U>);}template<class T>T&Concat(T&v,const T&vec){v.inser\
t(v.end(),vec.begin(),vec.end());return v;}namespace internal{template<class T,std::size_t N>auto make_vector(std::vecto\
r<int>&sizes,const T&init){if constexpr(N==1){return std::vector(sizes[0],init);}else{int size=sizes[N-1];sizes.pop_back\
();return std::vector(size,make_vector<T,N-1>(sizes,init));}}}template<class T,std::size_t N>auto make_vector(const int(\
&sizes)[N],const T&init=T()){std::vector s(std::rbegin(sizes),std::rend(sizes));return internal::make_vector<T,N>(s,init\
);}template<class F>struct rec_lambda{F f;rec_lambda(F&&f_): f(std::forward<F>(f_)){}template<class... Args>auto operato\
r()(Args&&... args)const{return f(*this,std::forward<Args>(args)...);}};namespace lambda{auto char_to_int=[](char c){ret\
urn c-'0';};auto lower_to_int=[](char c){return c-'a';};auto upper_to_int=[](char c){return c-'A';};auto int_to_char=[](\
int i)->char{return '0'+i;};auto int_to_lower=[](int i)->char{return 'a'+i;};auto int_to_upper=[](int i)->char{return 'A\
'+i;};auto is_odd=[](auto n){return n%2==1;};auto is_even=[](auto n){return n%2==0;};auto is_positive=[](auto n){return \
n>0;};auto is_negative=[](auto n){return n<0;};auto increment=[](auto n){return++n;};auto decrement=[](auto n){return--n\
;};auto self=[](const auto&n){return n;};auto first=[](const auto&n){return n.first;};auto second=[](const auto&n){retur\
n n.second;};template<class T>auto cast(){return [](const auto&n){return static_cast<T>(n);};};template<class T>auto equ\
al_to(const T&x){return [x](auto y){return x==y;};}template<std::size_t I>auto get(){return [](const auto&n){return std:\
:get<I>(n);};}template<class F>auto cmp(F&&f){return [f](const auto&a,const auto&b){return f(a)<f(b);};}}
#if __has_include(<library/dump.hpp>)
#define LOCAL
#include<library/dump.hpp>
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