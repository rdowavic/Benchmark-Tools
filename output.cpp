
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_brie_2__0_1__1 {
using t_ind_0 = Trie<2>;
t_ind_0 ind_0;
using t_tuple = t_ind_0::entry_type;
class iterator_0 : public std::iterator<std::forward_iterator_tag, t_tuple> {
    using nested_iterator = typename t_ind_0::iterator;
    nested_iterator nested;
    t_tuple value;
public:
    iterator_0() = default;
    iterator_0(const nested_iterator& iter) : nested(iter), value(orderOut_0(*iter)) {}
    iterator_0(const iterator_0& other) = default;
    iterator_0& operator=(const iterator_0& other) = default;
    bool operator==(const iterator_0& other) const {
        return nested == other.nested;
    }
    bool operator!=(const iterator_0& other) const {
        return !(*this == other);
    }
    const t_tuple& operator*() const {
        return value;
    }
    const t_tuple* operator->() const {
        return &value;
    }
    iterator_0& operator++() {
        ++nested;
        value = orderOut_0(*nested);
        return *this;
    }
};
using iterator = iterator_0;
struct context {
t_ind_0::op_context hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(orderIn_0(t), h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_brie_2__0_1__1& other) {
ind_0.insertAll(other.ind_0);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(orderIn_0(t), h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(orderIn_0(t), h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator_0> equalRange_1(const t_tuple& t, context& h) const {
auto r = ind_0.template getBoundaries<1>(orderIn_0(t), h.hints_0);
return make_range(iterator_0(r.begin()), iterator_0(r.end()));
}
range<iterator_0> equalRange_1(const t_tuple& t) const {
context h; return equalRange_1(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.partition(10000)) {
    res.push_back(make_range(iterator(cur.begin()), iterator(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return iterator_0(ind_0.begin());
}
iterator end() const {
return iterator_0(ind_0.end());
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 brie index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
};
struct t_brie_2__0_1__1__3 {
using t_ind_0 = Trie<2>;
t_ind_0 ind_0;
using t_tuple = t_ind_0::entry_type;
class iterator_0 : public std::iterator<std::forward_iterator_tag, t_tuple> {
    using nested_iterator = typename t_ind_0::iterator;
    nested_iterator nested;
    t_tuple value;
public:
    iterator_0() = default;
    iterator_0(const nested_iterator& iter) : nested(iter), value(orderOut_0(*iter)) {}
    iterator_0(const iterator_0& other) = default;
    iterator_0& operator=(const iterator_0& other) = default;
    bool operator==(const iterator_0& other) const {
        return nested == other.nested;
    }
    bool operator!=(const iterator_0& other) const {
        return !(*this == other);
    }
    const t_tuple& operator*() const {
        return value;
    }
    const t_tuple* operator->() const {
        return &value;
    }
    iterator_0& operator++() {
        ++nested;
        value = orderOut_0(*nested);
        return *this;
    }
};
using iterator = iterator_0;
struct context {
t_ind_0::op_context hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(orderIn_0(t), h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_brie_2__0_1__1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(orderIn_0(t), h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(orderIn_0(t), h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator_0> equalRange_1(const t_tuple& t, context& h) const {
auto r = ind_0.template getBoundaries<1>(orderIn_0(t), h.hints_0);
return make_range(iterator_0(r.begin()), iterator_0(r.end()));
}
range<iterator_0> equalRange_1(const t_tuple& t) const {
context h; return equalRange_1(t, h);
}
range<iterator_0> equalRange_3(const t_tuple& t, context& h) const {
auto r = ind_0.template getBoundaries<2>(orderIn_0(t), h.hints_0);
return make_range(iterator_0(r.begin()), iterator_0(r.end()));
}
range<iterator_0> equalRange_3(const t_tuple& t) const {
context h; return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.partition(10000)) {
    res.push_back(make_range(iterator(cur.begin()), iterator(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return iterator_0(ind_0.begin());
}
iterator end() const {
return iterator_0(ind_0.end());
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 brie index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
};
struct t_brie_2__0_1 {
using t_ind_0 = Trie<2>;
t_ind_0 ind_0;
using t_tuple = t_ind_0::entry_type;
class iterator_0 : public std::iterator<std::forward_iterator_tag, t_tuple> {
    using nested_iterator = typename t_ind_0::iterator;
    nested_iterator nested;
    t_tuple value;
public:
    iterator_0() = default;
    iterator_0(const nested_iterator& iter) : nested(iter), value(orderOut_0(*iter)) {}
    iterator_0(const iterator_0& other) = default;
    iterator_0& operator=(const iterator_0& other) = default;
    bool operator==(const iterator_0& other) const {
        return nested == other.nested;
    }
    bool operator!=(const iterator_0& other) const {
        return !(*this == other);
    }
    const t_tuple& operator*() const {
        return value;
    }
    const t_tuple* operator->() const {
        return &value;
    }
    iterator_0& operator++() {
        ++nested;
        value = orderOut_0(*nested);
        return *this;
    }
};
using iterator = iterator_0;
struct context {
t_ind_0::op_context hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(orderIn_0(t), h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_brie_2__0_1& other) {
ind_0.insertAll(other.ind_0);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(orderIn_0(t), h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(orderIn_0(t), h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.partition(10000)) {
    res.push_back(make_range(iterator(cur.begin()), iterator(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return iterator_0(ind_0.begin());
}
iterator end() const {
return iterator_0(ind_0.end());
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 brie index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
};
struct t_brie_2__0_1__3 {
using t_ind_0 = Trie<2>;
t_ind_0 ind_0;
using t_tuple = t_ind_0::entry_type;
class iterator_0 : public std::iterator<std::forward_iterator_tag, t_tuple> {
    using nested_iterator = typename t_ind_0::iterator;
    nested_iterator nested;
    t_tuple value;
public:
    iterator_0() = default;
    iterator_0(const nested_iterator& iter) : nested(iter), value(orderOut_0(*iter)) {}
    iterator_0(const iterator_0& other) = default;
    iterator_0& operator=(const iterator_0& other) = default;
    bool operator==(const iterator_0& other) const {
        return nested == other.nested;
    }
    bool operator!=(const iterator_0& other) const {
        return !(*this == other);
    }
    const t_tuple& operator*() const {
        return value;
    }
    const t_tuple* operator->() const {
        return &value;
    }
    iterator_0& operator++() {
        ++nested;
        value = orderOut_0(*nested);
        return *this;
    }
};
using iterator = iterator_0;
struct context {
t_ind_0::op_context hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(orderIn_0(t), h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_brie_2__0_1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(orderIn_0(t), h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(orderIn_0(t), h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator_0> equalRange_3(const t_tuple& t, context& h) const {
auto r = ind_0.template getBoundaries<2>(orderIn_0(t), h.hints_0);
return make_range(iterator_0(r.begin()), iterator_0(r.end()));
}
range<iterator_0> equalRange_3(const t_tuple& t) const {
context h; return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.partition(10000)) {
    res.push_back(make_range(iterator(cur.begin()), iterator(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return iterator_0(ind_0.begin());
}
iterator end() const {
return iterator_0(ind_0.end());
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 brie index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
res[1] = t[1];
return res;
}
};

class Sf_output : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
private:
static inline RamDomain wrapper_tonumber(const std::string& str) {
   RamDomain result=0; 
   try { result = stord(str); } catch(...) { 
     std::cerr << "error: wrong string provided by to_number(\"";
     std::cerr << str << "\") functor.\n";
     raise(SIGFPE);
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable
;// -- Table: base
std::unique_ptr<t_brie_2__0_1__1> rel_1_base = std::make_unique<t_brie_2__0_1__1>();
souffle::RelationWrapper<0,t_brie_2__0_1__1,Tuple<RamDomain,2>,2,true,false> wrapper_rel_1_base;
// -- Table: tc
std::unique_ptr<t_brie_2__0_1__1__3> rel_2_tc = std::make_unique<t_brie_2__0_1__1__3>();
souffle::RelationWrapper<1,t_brie_2__0_1__1__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_2_tc;
// -- Table: @delta_tc
std::unique_ptr<t_brie_2__0_1__1__3> rel_3_delta_tc = std::make_unique<t_brie_2__0_1__1__3>();
// -- Table: @new_tc
std::unique_ptr<t_brie_2__0_1__1__3> rel_4_new_tc = std::make_unique<t_brie_2__0_1__1__3>();
// -- Table: tcl
std::unique_ptr<t_brie_2__0_1__3> rel_5_tcl = std::make_unique<t_brie_2__0_1__3>();
souffle::RelationWrapper<2,t_brie_2__0_1__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_5_tcl;
// -- Table: @delta_tcl
std::unique_ptr<t_brie_2__0_1> rel_6_delta_tcl = std::make_unique<t_brie_2__0_1>();
// -- Table: @new_tcl
std::unique_ptr<t_brie_2__0_1> rel_7_new_tcl = std::make_unique<t_brie_2__0_1>();
// -- Table: tcr
std::unique_ptr<t_brie_2__0_1__3> rel_8_tcr = std::make_unique<t_brie_2__0_1__3>();
souffle::RelationWrapper<3,t_brie_2__0_1__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_8_tcr;
// -- Table: @delta_tcr
std::unique_ptr<t_brie_2__0_1__1> rel_9_delta_tcr = std::make_unique<t_brie_2__0_1__1>();
// -- Table: @new_tcr
std::unique_ptr<t_brie_2__0_1__1> rel_10_new_tcr = std::make_unique<t_brie_2__0_1__1>();
public:
Sf_output() : 
wrapper_rel_1_base(*rel_1_base,symTable,"base",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_2_tc(*rel_2_tc,symTable,"tc",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_5_tcl(*rel_5_tcl,symTable,"tcl",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}),

wrapper_rel_8_tcr(*rel_8_tcr,symTable,"tcr",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"node1","node2"}}){
addRelation("base",&wrapper_rel_1_base,1,0);
addRelation("tc",&wrapper_rel_2_tc,0,0);
addRelation("tcl",&wrapper_rel_5_tcl,0,0);
addRelation("tcr",&wrapper_rel_8_tcr,0,0);
}
~Sf_output() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(__EMBEDDED_SOUFFLE__) && defined(_OPENMP)
omp_set_num_threads(1);
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/base.facts"},{"name","base"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   base(X,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [18:1-18:22])_");
if (!rel_1_base->empty()) [&](){
auto part = rel_1_base->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_2_tc->insert(tuple,READ_OP_CONTEXT(rel_2_tc_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_3_delta_tc->insertAll(*rel_2_tc);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   tc(X,Z),
   tc(Z,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [19:1-19:28])_");
if (!rel_3_delta_tc->empty()&&!rel_2_tc->empty()) [&](){
auto part = rel_3_delta_tc->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_3_delta_tc_op_ctxt,rel_3_delta_tc->createContext());
CREATE_OP_CONTEXT(rel_4_new_tc_op_ctxt,rel_4_new_tc->createContext());
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_2_tc->equalRange_1(key,READ_OP_CONTEXT(rel_2_tc_op_ctxt));
for(const auto& env1 : range) {
if( ((!rel_2_tc->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_2_tc_op_ctxt))) && (!rel_3_delta_tc->contains(Tuple<RamDomain,2>({{env0[1],env1[1]}}),READ_OP_CONTEXT(rel_3_delta_tc_op_ctxt))))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_4_new_tc->insert(tuple,READ_OP_CONTEXT(rel_4_new_tc_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(tc(X,Y) :- 
   tc(X,Z),
   tc(Z,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [19:1-19:28])_");
if (!rel_3_delta_tc->empty()&&!rel_2_tc->empty()) [&](){
auto part = rel_2_tc->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_3_delta_tc_op_ctxt,rel_3_delta_tc->createContext());
CREATE_OP_CONTEXT(rel_4_new_tc_op_ctxt,rel_4_new_tc->createContext());
CREATE_OP_CONTEXT(rel_2_tc_op_ctxt,rel_2_tc->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_3_delta_tc->equalRange_1(key,READ_OP_CONTEXT(rel_3_delta_tc_op_ctxt));
for(const auto& env1 : range) {
if( !rel_2_tc->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_2_tc_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_4_new_tc->insert(tuple,READ_OP_CONTEXT(rel_4_new_tc_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_4_new_tc->empty()) break;
rel_2_tc->insertAll(*rel_4_new_tc);
std::swap(rel_3_delta_tc, rel_4_new_tc);
rel_4_new_tc->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_3_delta_tc->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_4_new_tc->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tc	)" <<  rel_2_tc->size() << std::endl;
}}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_tc->purge();
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tcl(X,Y) :- 
   base(X,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [10:1-10:24])_");
if (!rel_1_base->empty()) [&](){
auto part = rel_1_base->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_5_tcl_op_ctxt,rel_5_tcl->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_5_tcl->insert(tuple,READ_OP_CONTEXT(rel_5_tcl_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_6_delta_tcl->insertAll(*rel_5_tcl);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tcl(X,Y) :- 
   tcl(X,Z),
   base(Z,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [11:1-11:33])_");
if (!rel_6_delta_tcl->empty()&&!rel_1_base->empty()) [&](){
auto part = rel_6_delta_tcl->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_delta_tcl_op_ctxt,rel_6_delta_tcl->createContext());
CREATE_OP_CONTEXT(rel_7_new_tcl_op_ctxt,rel_7_new_tcl->createContext());
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_5_tcl_op_ctxt,rel_5_tcl->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_1_base->equalRange_1(key,READ_OP_CONTEXT(rel_1_base_op_ctxt));
for(const auto& env1 : range) {
if( !rel_5_tcl->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_5_tcl_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_7_new_tcl->insert(tuple,READ_OP_CONTEXT(rel_7_new_tcl_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_7_new_tcl->empty()) break;
rel_5_tcl->insertAll(*rel_7_new_tcl);
std::swap(rel_6_delta_tcl, rel_7_new_tcl);
rel_7_new_tcl->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_6_delta_tcl->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_7_new_tcl->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tcl	)" <<  rel_5_tcl->size() << std::endl;
}}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_5_tcl->purge();
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(tcr(X,Y) :- 
   base(X,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [14:1-14:23])_");
if (!rel_1_base->empty()) [&](){
auto part = rel_1_base->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_8_tcr_op_ctxt,rel_8_tcr->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_8_tcr->insert(tuple,READ_OP_CONTEXT(rel_8_tcr_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_9_delta_tcr->insertAll(*rel_8_tcr);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(tcr(X,Y) :- 
   base(X,Z),
   tcr(Z,Y).
in file /home/rdow6615/benchmarks/benchmarks/tc/tc.dl [15:1-15:33])_");
if (!rel_9_delta_tcr->empty()&&!rel_1_base->empty()) [&](){
auto part = rel_1_base->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_tcr_op_ctxt,rel_9_delta_tcr->createContext());
CREATE_OP_CONTEXT(rel_10_new_tcr_op_ctxt,rel_10_new_tcr->createContext());
CREATE_OP_CONTEXT(rel_1_base_op_ctxt,rel_1_base->createContext());
CREATE_OP_CONTEXT(rel_8_tcr_op_ctxt,rel_8_tcr->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_9_delta_tcr->equalRange_1(key,READ_OP_CONTEXT(rel_9_delta_tcr_op_ctxt));
for(const auto& env1 : range) {
if( !rel_8_tcr->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_8_tcr_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_10_new_tcr->insert(tuple,READ_OP_CONTEXT(rel_10_new_tcr_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_10_new_tcr->empty()) break;
rel_8_tcr->insertAll(*rel_10_new_tcr);
std::swap(rel_9_delta_tcr, rel_10_new_tcr);
rel_10_new_tcr->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_9_delta_tcr->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_10_new_tcr->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tcr	)" <<  rel_8_tcr->size() << std::endl;
}}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_base->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_8_tcr->purge();
}();
/* END STRATUM 3 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_base:\n";
rel_1_base->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_tc:\n";
rel_2_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_delta_tc:\n";
rel_3_delta_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_new_tc:\n";
rel_4_new_tc->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_tcl:\n";
rel_5_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_delta_tcl:\n";
rel_6_delta_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_new_tcl:\n";
rel_7_new_tcl->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_tcr:\n";
rel_8_tcr->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_delta_tcr:\n";
rel_9_delta_tcr->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_new_tcr:\n";
rel_10_new_tcr->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override { runFunction(".", ".", stratumIndex, false); }
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override { runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tc	)" <<  rel_2_tc->size() << std::endl;
}{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tcl	)" <<  rel_5_tcl->size() << std::endl;
}{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(tcr	)" <<  rel_8_tcr->size() << std::endl;
}}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/base.facts"},{"name","base"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_base");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_1_base);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_output(){return new Sf_output;}
SymbolTable *getST_output(SouffleProgram *p){return &reinterpret_cast<Sf_output*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_output: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_output();
};
public:
factory_Sf_output() : ProgramFactory("output"){}
};
static factory_Sf_output __factory_Sf_output_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(tc/tc.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
#if defined(_OPENMP) 
omp_set_nested(true);

#endif
souffle::Sf_output obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
