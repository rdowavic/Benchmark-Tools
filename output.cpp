
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_brie_2__0_1__1_0__1__2 {
using t_ind_0 = Trie<2>;
t_ind_0 ind_0;
using t_ind_1 = Trie<2>;
t_ind_1 ind_1;
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
class iterator_1 : public std::iterator<std::forward_iterator_tag, t_tuple> {
    using nested_iterator = typename t_ind_1::iterator;
    nested_iterator nested;
    t_tuple value;
public:
    iterator_1() = default;
    iterator_1(const nested_iterator& iter) : nested(iter), value(orderOut_1(*iter)) {}
    iterator_1(const iterator_1& other) = default;
    iterator_1& operator=(const iterator_1& other) = default;
    bool operator==(const iterator_1& other) const {
        return nested == other.nested;
    }
    bool operator!=(const iterator_1& other) const {
        return !(*this == other);
    }
    const t_tuple& operator*() const {
        return value;
    }
    const t_tuple* operator->() const {
        return &value;
    }
    iterator_1& operator++() {
        ++nested;
        value = orderOut_1(*nested);
        return *this;
    }
};
using iterator = iterator_0;
struct context {
t_ind_0::op_context hints_0;
t_ind_1::op_context hints_1;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(orderIn_0(t), h.hints_0)) {
ind_1.insert(orderIn_1(t), h.hints_1);
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
void insertAll(t_brie_2__0_1__1_0__1__2& other) {
ind_0.insertAll(other.ind_0);
ind_1.insertAll(other.ind_1);
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
range<iterator_1> equalRange_2(const t_tuple& t, context& h) const {
auto r = ind_1.template getBoundaries<1>(orderIn_1(t), h.hints_1);
return make_range(iterator_1(r.begin()), iterator_1(r.end()));
}
range<iterator_1> equalRange_2(const t_tuple& t) const {
context h; return equalRange_2(t, h);
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
ind_1.clear();
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
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 2 brie index [1,0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_1.get_boundaries.getHits() << "/" << stats_1.get_boundaries.getMisses() << "/" << stats_1.get_boundaries.getAccesses() << "\n";
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
static t_tuple orderIn_1(const t_tuple& t) {
t_tuple res;
res[0] = t[1];
res[1] = t[0];
return res;
}
static t_tuple orderOut_1(const t_tuple& t) {
t_tuple res;
res[1] = t[0];
res[0] = t[1];
return res;
}
};
struct t_brie_2__1_0__2__3 {
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
void insertAll(t_brie_2__1_0__2__3& other) {
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
range<iterator_0> equalRange_2(const t_tuple& t, context& h) const {
auto r = ind_0.template getBoundaries<1>(orderIn_0(t), h.hints_0);
return make_range(iterator_0(r.begin()), iterator_0(r.end()));
}
range<iterator_0> equalRange_2(const t_tuple& t) const {
context h; return equalRange_2(t, h);
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
o << prefix << "arity 2 brie index [1,0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[1];
res[1] = t[0];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[1] = t[0];
res[0] = t[1];
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
struct t_brie_1__0 {
using t_ind_0 = Trie<1>;
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
RamDomain data[1];
std::copy(ramDomain, ramDomain + 1, data);
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
void insertAll(t_brie_1__0& other) {
ind_0.insertAll(other.ind_0);
}
bool insert(RamDomain a0) {
RamDomain data[1] = {a0};
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
o << prefix << "arity 1 brie index [0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Range-query: " << stats_0.get_boundaries.getHits() << "/" << stats_0.get_boundaries.getMisses() << "/" << stats_0.get_boundaries.getAccesses() << "\n";
}
static t_tuple orderIn_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
return res;
}
static t_tuple orderOut_0(const t_tuple& t) {
t_tuple res;
res[0] = t[0];
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
;// -- Table: edge
std::unique_ptr<t_brie_2__0_1__1_0__1__2> rel_1_edge = std::make_unique<t_brie_2__0_1__1_0__1__2>();
souffle::RelationWrapper<0,t_brie_2__0_1__1_0__1__2,Tuple<RamDomain,2>,2,true,false> wrapper_rel_1_edge;
// -- Table: is_after
std::unique_ptr<t_brie_2__1_0__2__3> rel_2_is_after = std::make_unique<t_brie_2__1_0__2__3>();
souffle::RelationWrapper<1,t_brie_2__1_0__2__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_2_is_after;
// -- Table: @delta_is_after
std::unique_ptr<t_brie_2__1_0__2__3> rel_3_delta_is_after = std::make_unique<t_brie_2__1_0__2__3>();
// -- Table: @new_is_after
std::unique_ptr<t_brie_2__1_0__2__3> rel_4_new_is_after = std::make_unique<t_brie_2__1_0__2__3>();
// -- Table: is_before
std::unique_ptr<t_brie_2__0_1__1__3> rel_5_is_before = std::make_unique<t_brie_2__0_1__1__3>();
souffle::RelationWrapper<2,t_brie_2__0_1__1__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_5_is_before;
// -- Table: @delta_is_before
std::unique_ptr<t_brie_2__0_1__1__3> rel_6_delta_is_before = std::make_unique<t_brie_2__0_1__1__3>();
// -- Table: @new_is_before
std::unique_ptr<t_brie_2__0_1__1__3> rel_7_new_is_before = std::make_unique<t_brie_2__0_1__1__3>();
// -- Table: vertex
std::unique_ptr<t_brie_1__0> rel_8_vertex = std::make_unique<t_brie_1__0>();
// -- Table: indices
std::unique_ptr<t_brie_2__0_1__3> rel_9_indices = std::make_unique<t_brie_2__0_1__3>();
souffle::RelationWrapper<3,t_brie_2__0_1__3,Tuple<RamDomain,2>,2,false,true> wrapper_rel_9_indices;
// -- Table: @delta_indices
std::unique_ptr<t_brie_2__0_1__1> rel_10_delta_indices = std::make_unique<t_brie_2__0_1__1>();
// -- Table: @new_indices
std::unique_ptr<t_brie_2__0_1__1> rel_11_new_indices = std::make_unique<t_brie_2__0_1__1>();
// -- Table: index
std::unique_ptr<t_brie_2__0_1> rel_12_index = std::make_unique<t_brie_2__0_1>();
souffle::RelationWrapper<4,t_brie_2__0_1,Tuple<RamDomain,2>,2,false,true> wrapper_rel_12_index;
public:
Sf_output() : 
wrapper_rel_1_edge(*rel_1_edge,symTable,"edge",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"v1","v2"}}),

wrapper_rel_2_is_after(*rel_2_is_after,symTable,"is_after",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"v1","v2"}}),

wrapper_rel_5_is_before(*rel_5_is_before,symTable,"is_before",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"v1","v2"}}),

wrapper_rel_9_indices(*rel_9_indices,symTable,"indices",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"v","i"}}),

wrapper_rel_12_index(*rel_12_index,symTable,"index",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"v","i"}}){
addRelation("edge",&wrapper_rel_1_edge,1,0);
addRelation("is_after",&wrapper_rel_2_is_after,0,0);
addRelation("is_before",&wrapper_rel_5_is_before,0,0);
addRelation("indices",&wrapper_rel_9_indices,0,0);
addRelation("index",&wrapper_rel_12_index,0,0);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/edge.facts"},{"name","edge"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_edge);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   edge(y,x).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [38:1-39:16])_");
if (!rel_1_edge->empty()) [&](){
auto part = rel_1_edge->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,rel_2_is_after->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[0])}});
rel_2_is_after->insert(tuple,READ_OP_CONTEXT(rel_2_is_after_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_3_delta_is_after->insertAll(*rel_2_is_after);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   is_after(z,x),
   is_after(y,z).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [42:1-44:20])_");
if (!rel_3_delta_is_after->empty()&&!rel_2_is_after->empty()) [&](){
auto part = rel_3_delta_is_after->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_3_delta_is_after_op_ctxt,rel_3_delta_is_after->createContext());
CREATE_OP_CONTEXT(rel_4_new_is_after_op_ctxt,rel_4_new_is_after->createContext());
CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,rel_2_is_after->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{0,env0[0]}});
auto range = rel_2_is_after->equalRange_2(key,READ_OP_CONTEXT(rel_2_is_after_op_ctxt));
for(const auto& env1 : range) {
if( ((!rel_2_is_after->contains(Tuple<RamDomain,2>({{env0[1],env1[0]}}),READ_OP_CONTEXT(rel_2_is_after_op_ctxt))) && (!rel_3_delta_is_after->contains(Tuple<RamDomain,2>({{env1[0],env0[0]}}),READ_OP_CONTEXT(rel_3_delta_is_after_op_ctxt))))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[0])}});
rel_4_new_is_after->insert(tuple,READ_OP_CONTEXT(rel_4_new_is_after_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(is_after(x,y) :- 
   is_after(z,x),
   is_after(y,z).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [42:1-44:20])_");
if (!rel_3_delta_is_after->empty()&&!rel_2_is_after->empty()) [&](){
auto part = rel_2_is_after->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_3_delta_is_after_op_ctxt,rel_3_delta_is_after->createContext());
CREATE_OP_CONTEXT(rel_4_new_is_after_op_ctxt,rel_4_new_is_after->createContext());
CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,rel_2_is_after->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{0,env0[0]}});
auto range = rel_3_delta_is_after->equalRange_2(key,READ_OP_CONTEXT(rel_3_delta_is_after_op_ctxt));
for(const auto& env1 : range) {
if( !rel_2_is_after->contains(Tuple<RamDomain,2>({{env0[1],env1[0]}}),READ_OP_CONTEXT(rel_2_is_after_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env1[0])}});
rel_4_new_is_after->insert(tuple,READ_OP_CONTEXT(rel_4_new_is_after_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_4_new_is_after->empty()) break;
rel_2_is_after->insertAll(*rel_4_new_is_after);
std::swap(rel_3_delta_is_after, rel_4_new_is_after);
rel_4_new_is_after->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_3_delta_is_after->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_4_new_is_after->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(is_after	)" <<  rel_2_is_after->size() << std::endl;
}}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   edge(x,y).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [29:1-30:16])_");
if (!rel_1_edge->empty()) [&](){
auto part = rel_1_edge->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,rel_5_is_before->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_5_is_before->insert(tuple,READ_OP_CONTEXT(rel_5_is_before_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_6_delta_is_before->insertAll(*rel_5_is_before);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   is_before(x,z),
   is_before(z,y).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [33:1-35:21])_");
if (!rel_6_delta_is_before->empty()&&!rel_5_is_before->empty()) [&](){
auto part = rel_6_delta_is_before->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_delta_is_before_op_ctxt,rel_6_delta_is_before->createContext());
CREATE_OP_CONTEXT(rel_7_new_is_before_op_ctxt,rel_7_new_is_before->createContext());
CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,rel_5_is_before->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_5_is_before->equalRange_1(key,READ_OP_CONTEXT(rel_5_is_before_op_ctxt));
for(const auto& env1 : range) {
if( ((!rel_5_is_before->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_5_is_before_op_ctxt))) && (!rel_6_delta_is_before->contains(Tuple<RamDomain,2>({{env0[1],env1[1]}}),READ_OP_CONTEXT(rel_6_delta_is_before_op_ctxt))))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_7_new_is_before->insert(tuple,READ_OP_CONTEXT(rel_7_new_is_before_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(is_before(x,y) :- 
   is_before(x,z),
   is_before(z,y).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [33:1-35:21])_");
if (!rel_6_delta_is_before->empty()&&!rel_5_is_before->empty()) [&](){
auto part = rel_5_is_before->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_delta_is_before_op_ctxt,rel_6_delta_is_before->createContext());
CREATE_OP_CONTEXT(rel_7_new_is_before_op_ctxt,rel_7_new_is_before->createContext());
CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,rel_5_is_before->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({{env0[1],0}});
auto range = rel_6_delta_is_before->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_is_before_op_ctxt));
for(const auto& env1 : range) {
if( !rel_5_is_before->contains(Tuple<RamDomain,2>({{env0[0],env1[1]}}),READ_OP_CONTEXT(rel_5_is_before_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}});
rel_7_new_is_before->insert(tuple,READ_OP_CONTEXT(rel_7_new_is_before_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_7_new_is_before->empty()) break;
rel_5_is_before->insertAll(*rel_7_new_is_before);
std::swap(rel_6_delta_is_before, rel_7_new_is_before);
rel_7_new_is_before->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_6_delta_is_before->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_7_new_is_before->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(is_before	)" <<  rel_5_is_before->size() << std::endl;
}}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(vertex(v) :- 
   edge(v,_).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [12:1-12:24])_");
if (!rel_1_edge->empty()) [&](){
auto part = rel_1_edge->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,rel_8_vertex->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,1> tuple({{static_cast<RamDomain>(env0[0])}});
rel_8_vertex->insert(tuple,READ_OP_CONTEXT(rel_8_vertex_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(vertex(v) :- 
   edge(_,v).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [13:1-13:24])_");
if (!rel_1_edge->empty()) [&](){
auto part = rel_1_edge->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,rel_8_vertex->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,1> tuple({{static_cast<RamDomain>(env0[1])}});
rel_8_vertex->insert(tuple,READ_OP_CONTEXT(rel_8_vertex_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(indices(x,0) :- 
   vertex(x),
   !edge(_,x),
   !edge(x,_).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [47:1-50:17])_");
if (!rel_8_vertex->empty()) [&](){
auto part = rel_8_vertex->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,rel_9_indices->createContext());
CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,rel_8_vertex->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( ((rel_1_edge->equalRange_2(Tuple<RamDomain,2>({{0,env0[0]}}),READ_OP_CONTEXT(rel_1_edge_op_ctxt)).empty()) && (rel_1_edge->equalRange_1(Tuple<RamDomain,2>({{env0[0],0}}),READ_OP_CONTEXT(rel_1_edge_op_ctxt)).empty()))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(RamDomain(0))}});
rel_9_indices->insert(tuple,READ_OP_CONTEXT(rel_9_indices_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(indices(x,1) :- 
   vertex(x),
   edge(x,_),
   !edge(_,x).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [53:1-56:16])_");
if (!rel_1_edge->empty()&&!rel_8_vertex->empty()) [&](){
auto part = rel_8_vertex->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_edge_op_ctxt,rel_1_edge->createContext());
CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,rel_9_indices->createContext());
CREATE_OP_CONTEXT(rel_8_vertex_op_ctxt,rel_8_vertex->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( rel_1_edge->equalRange_2(Tuple<RamDomain,2>({{0,env0[0]}}),READ_OP_CONTEXT(rel_1_edge_op_ctxt)).empty()) {
const Tuple<RamDomain,2> key({{env0[0],0}});
auto range = rel_1_edge->equalRange_1(key,READ_OP_CONTEXT(rel_1_edge_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(RamDomain(1))}});
rel_9_indices->insert(tuple,READ_OP_CONTEXT(rel_9_indices_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();rel_10_delta_indices->insertAll(*rel_9_indices);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(indices(x,(i+1)) :- 
   is_before(y,x),
   is_after(x,y),
   indices(y,i),
   !is_before(x,y).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [59:1-63:19])_");
if (!rel_10_delta_indices->empty()&&!rel_2_is_after->empty()&&!rel_5_is_before->empty()) [&](){
auto part = rel_5_is_before->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_10_delta_indices_op_ctxt,rel_10_delta_indices->createContext());
CREATE_OP_CONTEXT(rel_11_new_indices_op_ctxt,rel_11_new_indices->createContext());
CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,rel_9_indices->createContext());
CREATE_OP_CONTEXT(rel_2_is_after_op_ctxt,rel_2_is_after->createContext());
CREATE_OP_CONTEXT(rel_5_is_before_op_ctxt,rel_5_is_before->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( !rel_5_is_before->contains(Tuple<RamDomain,2>({{env0[1],env0[0]}}),READ_OP_CONTEXT(rel_5_is_before_op_ctxt))) {
const Tuple<RamDomain,2> key({{env0[1],env0[0]}});
auto range = rel_2_is_after->equalRange_3(key,READ_OP_CONTEXT(rel_2_is_after_op_ctxt));
if(!range.empty()) {
const Tuple<RamDomain,2> key({{env0[0],0}});
auto range = rel_10_delta_indices->equalRange_1(key,READ_OP_CONTEXT(rel_10_delta_indices_op_ctxt));
for(const auto& env2 : range) {
if( !rel_9_indices->contains(Tuple<RamDomain,2>({{env0[1],(env2[1]) + (RamDomain(1))}}),READ_OP_CONTEXT(rel_9_indices_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>((env2[1]) + (RamDomain(1)))}});
rel_11_new_indices->insert(tuple,READ_OP_CONTEXT(rel_11_new_indices_op_ctxt));
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_11_new_indices->empty()) break;
rel_9_indices->insertAll(*rel_11_new_indices);
std::swap(rel_10_delta_indices, rel_11_new_indices);
rel_11_new_indices->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_10_delta_indices->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_11_new_indices->purge();
if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(indices	)" <<  rel_9_indices->size() << std::endl;
}}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_8_vertex->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_edge->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_5_is_before->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_is_after->purge();
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(index(x,i) :- 
   indices(x,i),
   !indices(x,(i+1)).
in file /home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl [66:1-68:22])_");
if (!rel_9_indices->empty()) [&](){
auto part = rel_9_indices->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_12_index_op_ctxt,rel_12_index->createContext());
CREATE_OP_CONTEXT(rel_9_indices_op_ctxt,rel_9_indices->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( !rel_9_indices->contains(Tuple<RamDomain,2>({{env0[0],(env0[1]) + (RamDomain(1))}}),READ_OP_CONTEXT(rel_9_indices_op_ctxt))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_12_index->insert(tuple,READ_OP_CONTEXT(rel_12_index_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if (performIO) {
{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(index	)" <<  rel_12_index->size() << std::endl;
}}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_9_indices->purge();
}();
/* END STRATUM 5 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_edge:\n";
rel_1_edge->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_is_after:\n";
rel_2_is_after->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_delta_is_after:\n";
rel_3_delta_is_after->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_new_is_after:\n";
rel_4_new_is_after->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_is_before:\n";
rel_5_is_before->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_delta_is_before:\n";
rel_6_delta_is_before->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_new_is_before:\n";
rel_7_new_is_before->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_vertex:\n";
rel_8_vertex->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_indices:\n";
rel_9_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_delta_indices:\n";
rel_10_delta_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_new_indices:\n";
rel_11_new_indices->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_index:\n";
rel_12_index->printHintStatistics(std::cout,"  ");
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
std::cout << R"(is_after	)" <<  rel_2_is_after->size() << std::endl;
}{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(is_before	)" <<  rel_5_is_before->size() << std::endl;
}{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(indices	)" <<  rel_9_indices->size() << std::endl;
}{ auto lease = getOutputLock().acquire(); 
(void)lease;
std::cout << R"(index	)" <<  rel_12_index->size() << std::endl;
}}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/edge.facts"},{"name","edge"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_edge);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_edge");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_1_edge);
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
souffle::CmdOptions opt(R"(/home/rdow6615/benchmarks/benchmarks/topological_ordering/topological_ordering.dl)",
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
