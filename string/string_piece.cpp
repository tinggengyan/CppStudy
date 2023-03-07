//
// Created by TinggengYan on 2023/3/6.
//

#ifndef CPPSTUDY_STRING_DEFINITION_H
#define CPPSTUDY_STRING_DEFINITION_H

#include <cstddef>
#include <algorithm>

template<typename CharT, typename Traits = std::char_traits<CharT>>
class BasicStringPiece;

using StringPiece = BasicStringPiece<char>;
using StringPiece16 = BasicStringPiece<char16_t>;
using WStringPiece = BasicStringPiece<wchar_t>;

namespace internal {
    size_t find(StringPiece self, StringPiece s, size_t pos);

    size_t find(StringPiece16 self, StringPiece16 s, size_t pos);

    size_t find_last_not_of(StringPiece self, StringPiece s, size_t pos);

    size_t find_first_not_of(StringPiece self, StringPiece s, size_t pos);

    size_t find_last_of(StringPiece self, StringPiece s, size_t pos);

    size_t find_first_of(StringPiece self, StringPiece s, size_t pos);

    size_t rfind(StringPiece self, StringPiece s, size_t pos);
}

template<typename CharT, typename Traits>
class BasicStringPiece {
public:
    using traits_type = Traits;
    using value_type = CharT;
    using pointer = CharT *;
    using const_pointer = const CharT *;
    using reference = CharT &;
    using const_reference = const CharT &;
    using const_iterator = const CharT *;
    using iterator = const_iterator;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reverse_iterator = const_reverse_iterator;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    constexpr BasicStringPiece() noexcept: ptr_(nullptr), length_(0) {}

    constexpr BasicStringPiece(const BasicStringPiece &other) noexcept = default;

    constexpr BasicStringPiece &operator=(const BasicStringPiece &view) noexcept =
    default;

    constexpr BasicStringPiece(const CharT *s, size_t count)
            : ptr_(s), length_(count) {
        // Intentional STL deviation: Check the string length fits in
        // `difference_type`. No valid buffer can exceed this type, otherwise
        // pointer arithmetic would not be defined. This helps avoid bugs where
        // `count` was computed from an underflow or negative sentinel value.
    }

    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr BasicStringPiece(const CharT *s)
            : ptr_(s), length_(s ? traits_type::length(s) : 0) {
        // Intentional STL deviation: Null-check instead of UB.
        CHECK(s);
    }

    // Explicitly disallow construction from nullptr. Note that this does not
    // catch construction from runtime strings that might be null.
    // Note: The following is just a more elaborate way of spelling
    // `BasicStringPiece(nullptr_t) = delete`, but unfortunately the terse form is
    // not supported by the PNaCl toolchain.
    template<class T, class = std::enable_if_t<std::is_null_pointer<T>::value>>
    BasicStringPiece(T) {
        static_assert(sizeof(T) == 0,  // Always false.
                      "StringPiece does not support construction from nullptr, use "
                      "the default constructor instead.");
    }

    // These are necessary because std::basic_string provides construction from
    // (an object convertible to) a std::basic_string_view, as well as an explicit
    // cast operator to a std::basic_string_view, but (obviously) not from/to a
    // BasicStringPiece.
    BasicStringPiece(const std::basic_string<CharT> &str)
            : ptr_(str.data()), length_(str.size()) {}

    explicit operator std::basic_string<CharT>() const {
        return std::basic_string<CharT>(data(), size());
    }

    constexpr const_iterator begin() const noexcept { return ptr_; }

    constexpr const_iterator cbegin() const noexcept { return ptr_; }

    constexpr const_iterator end() const noexcept { return ptr_ + length_; }

    constexpr const_iterator cend() const noexcept { return ptr_ + length_; }

    constexpr const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(ptr_ + length_);
    }

    constexpr const_reverse_iterator crbegin() const noexcept {
        return const_reverse_iterator(ptr_ + length_);
    }

    constexpr const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(ptr_);
    }

    constexpr const_reverse_iterator crend() const noexcept {
        return const_reverse_iterator(ptr_);
    }

    constexpr const_reference operator[](size_type pos) const {
        // Intentional STL deviation: Bounds-check instead of UB.
        return at(pos);
    }

    constexpr const_reference at(size_type pos) const {
        return data()[pos];
    }

    constexpr const_reference front() const { return operator[](0); }

    constexpr const_reference back() const { return operator[](size() - 1); }

    constexpr const_pointer data() const noexcept { return ptr_; }

    constexpr size_type size() const noexcept { return length_; }

    constexpr size_type length() const noexcept { return length_; }

    constexpr size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(CharT);
    }

    [[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

    constexpr void remove_prefix(size_type n) {
        // Intentional STL deviation: Bounds-check instead of UB.
        CHECK_LE(n, size());
        ptr_ += n;
        length_ -= n;
    }

    constexpr void remove_suffix(size_type n) {
        // Intentional STL deviation: Bounds-check instead of UB.
        CHECK_LE(n, size());
        length_ -= n;
    }

    constexpr void swap(BasicStringPiece &v) noexcept {
        // Note: Cannot use std::swap() since it is not constexpr until C++20.
        const const_pointer ptr = ptr_;
        ptr_ = v.ptr_;
        v.ptr_ = ptr;
        const size_type length = length_;
        length_ = v.length_;
        v.length_ = length;
    }

    constexpr size_type copy(CharT *dest,
                             size_type count,
                             size_type pos = 0) const {
        CHECK_LE(pos, size());
        const size_type rcount = std::min(count, size() - pos);
        traits_type::copy(dest, data() + pos, rcount);
        return rcount;
    }

    constexpr BasicStringPiece substr(size_type pos = 0,
                                      size_type count = npos) const {
        CHECK_LE(pos, size());
        const size_type rcount = std::min(count, size() - pos);
        return {data() + pos, rcount};
    }

    constexpr int compare(BasicStringPiece v) const noexcept {
        const size_type rlen = std::min(size(), v.size());
        const int result = traits_type::compare(data(), v.data(), rlen);
        if (result != 0)
            return result;
        if (size() == v.size())
            return 0;
        return size() < v.size() ? -1 : 1;
    }

    constexpr int compare(size_type pos1,
                          size_type count1,
                          BasicStringPiece v) const {
        return substr(pos1, count1).compare(v);
    }

    constexpr int compare(size_type pos1,
                          size_type count1,
                          BasicStringPiece v,
                          size_type pos2,
                          size_type count2) const {
        return substr(pos1, count1).compare(v.substr(pos2, count2));
    }

    constexpr int compare(const CharT *s) const {
        return compare(BasicStringPiece(s));
    }

    constexpr int compare(size_type pos1,
                          size_type count1,
                          const CharT *s) const {
        return substr(pos1, count1).compare(BasicStringPiece(s));
    }

    constexpr int compare(size_type pos1,
                          size_type count1,
                          const CharT *s,
                          size_type count2) const {
        return substr(pos1, count1).compare(BasicStringPiece(s, count2));
    }

    constexpr bool is_constant_evaluated() noexcept {
        return __builtin_is_constant_evaluated();
    }


    constexpr size_type find(BasicStringPiece v,
                             size_type pos = 0) const noexcept {
        if (is_constant_evaluated()) {
            if (v.size() > size())
                return npos;
            for (size_type p = pos; p <= size() - v.size(); ++p) {
                if (!compare(p, v.size(), v))
                    return p;
            }
            return npos;
        }

        return internal::find(*this, v, pos);
    }

    constexpr size_type find(CharT ch, size_type pos = 0) const noexcept {
        if (pos >= size())
            return npos;

        const const_pointer result = traits_type::find(data() + pos, size() - pos, ch);
        return result ? static_cast<size_type>(result - data()) : npos;
    }

    constexpr size_type find(const CharT *s,
                             size_type pos,
                             size_type count) const {
        return find(BasicStringPiece(s, count), pos);
    }

    constexpr size_type find(const CharT *s, size_type pos = 0) const {
        return find(BasicStringPiece(s), pos);
    }

    constexpr size_type rfind(BasicStringPiece v,
                              size_type pos = npos) const noexcept {
        if (is_constant_evaluated()) {
            if (v.size() > size())
                return npos;
            for (size_type p = std::min(size() - v.size(), pos);; --p) {
                if (!compare(p, v.size(), v))
                    return p;
                if (!p)
                    break;
            }
            return npos;
        }

        return internal::rfind(*this, v, pos);
    }

    constexpr size_type rfind(CharT c, size_type pos = npos) const noexcept {
        if (empty())
            return npos;

        for (size_t i = std::min(pos, size() - 1);; --i) {
            if (data()[i] == c)
                return i;

            if (i == 0)
                break;
        }
        return npos;
    }

    constexpr size_type rfind(const CharT *s,
                              size_type pos,
                              size_type count) const {
        return rfind(BasicStringPiece(s, count), pos);
    }

    constexpr size_type rfind(const CharT *s, size_type pos = npos) const {
        return rfind(BasicStringPiece(s), pos);
    }

    constexpr size_type find_first_of(BasicStringPiece v,
                                      size_type pos = 0) const noexcept {
        if (is_constant_evaluated()) {
            if (empty() || v.empty())
                return npos;
            for (size_type p = pos; p < size(); ++p) {
                if (v.find(data()[p]) != npos)
                    return p;
            }
            return npos;
        }

        return internal::find_first_of(*this, v, pos);
    }

    constexpr size_type find_first_of(CharT c, size_type pos = 0) const noexcept {
        return find(c, pos);
    }

    constexpr size_type find_first_of(const CharT *s,
                                      size_type pos,
                                      size_type count) const {
        return find_first_of(BasicStringPiece(s, count), pos);
    }

    constexpr size_type find_first_of(const CharT *s, size_type pos = 0) const {
        return find_first_of(BasicStringPiece(s), pos);
    }

    constexpr size_type find_last_of(BasicStringPiece v,
                                     size_type pos = npos) const noexcept {
        if (is_constant_evaluated()) {
            if (empty() || v.empty())
                return npos;
            for (size_type p = std::min(pos, size() - 1);; --p) {
                if (v.find(data()[p]) != npos)
                    return p;
                if (!p)
                    break;
            }
            return npos;
        }

        return internal::find_last_of(*this, v, pos);
    }

    constexpr size_type find_last_of(CharT c,
                                     size_type pos = npos) const noexcept {
        return rfind(c, pos);
    }

    constexpr size_type find_last_of(const CharT *s,
                                     size_type pos,
                                     size_type count) const {
        return find_last_of(BasicStringPiece(s, count), pos);
    }

    constexpr size_type find_last_of(const CharT *s, size_type pos = npos) const {
        return find_last_of(BasicStringPiece(s), pos);
    }

    constexpr size_type find_first_not_of(BasicStringPiece v,
                                          size_type pos = 0) const noexcept {
        if (is_constant_evaluated()) {
            if (empty())
                return npos;
            for (size_type p = pos; p < size(); ++p) {
                if (v.find(data()[p]) == npos)
                    return p;
            }
            return npos;
        }

        return internal::find_first_not_of(*this, v, pos);
    }

    constexpr size_type find_first_not_of(CharT c,
                                          size_type pos = 0) const noexcept {
        if (empty())
            return npos;

        for (; pos < size(); ++pos) {
            if (data()[pos] != c)
                return pos;
        }
        return npos;
    }

    constexpr size_type find_first_not_of(const CharT *s,
                                          size_type pos,
                                          size_type count) const {
        return find_first_not_of(BasicStringPiece(s, count), pos);
    }

    constexpr size_type find_first_not_of(const CharT *s,
                                          size_type pos = 0) const {
        return find_first_not_of(BasicStringPiece(s), pos);
    }

    constexpr size_type find_last_not_of(BasicStringPiece v,
                                         size_type pos = npos) const noexcept {
        if (is_constant_evaluated()) {
            if (empty())
                return npos;
            for (size_type p = std::min(pos, size() - 1);; --p) {
                if (v.find(data()[p]) == npos)
                    return p;
                if (!p)
                    break;
            }
            return npos;
        }

        return internal::find_last_not_of(*this, v, pos);
    }

    constexpr size_type find_last_not_of(CharT c,
                                         size_type pos = npos) const noexcept {
        if (empty())
            return npos;

        for (size_t i = std::min(pos, size() - 1);; --i) {
            if (data()[i] != c)
                return i;
            if (i == 0)
                break;
        }
        return npos;
    }

    constexpr size_type find_last_not_of(const CharT *s,
                                         size_type pos,
                                         size_type count) const {
        return find_last_not_of(BasicStringPiece(s, count), pos);
    }

    constexpr size_type find_last_not_of(const CharT *s,
                                         size_type pos = npos) const {
        return internal::find_last_not_of(BasicStringPiece(s), pos);
    }

    static constexpr size_type npos = size_type(-1);

protected:
    const_pointer ptr_;
    size_type length_;
};

namespace internal {

    inline void BuildLookupTable(StringPiece characters_wanted, bool *table) {
        const size_t length = characters_wanted.length();
        const char *const data = characters_wanted.data();
        for (size_t i = 0; i < length; ++i) {
            table[static_cast<unsigned char>(data[i])] = true;
        }
    }

    template<typename T, typename CharT = typename T::value_type>
    size_t findT(T self, T s, size_t pos) {
        if (pos > self.size())
            return BasicStringPiece<CharT>::npos;

        typename BasicStringPiece<CharT>::const_iterator result =
                std::search(self.begin() + pos, self.end(), s.begin(), s.end());
        const size_t xpos =
                static_cast<size_t>(result - self.begin());
        return xpos + s.size() <= self.size() ? xpos : BasicStringPiece<CharT>::npos;
    }

    size_t find(StringPiece self, StringPiece s, size_t pos) {
        return findT(self, s, pos);
    }

    size_t find(StringPiece16 self, StringPiece16 s, size_t pos) {
        return findT(self, s, pos);
    }

    template<typename T, typename CharT = typename T::value_type>
    size_t rfindT(T self, T s, size_t pos) {
        if (self.size() < s.size())
            return BasicStringPiece<CharT>::npos;

        if (s.empty())
            return std::min(self.size(), pos);

        typename BasicStringPiece<CharT>::const_iterator last =
                self.begin() + std::min(self.size() - s.size(), pos) + s.size();
        typename BasicStringPiece<CharT>::const_iterator result =
                std::find_end(self.begin(), last, s.begin(), s.end());
        return result != last ? static_cast<size_t>(result - self.begin())
                              : BasicStringPiece<CharT>::npos;
    }

    size_t rfind(StringPiece self, StringPiece s, size_t pos) {
        return rfindT(self, s, pos);
    }

    size_t rfind(StringPiece16 self, StringPiece16 s, size_t pos) {
        return rfindT(self, s, pos);
    }

// 8-bit version using lookup table.
    size_t find_first_of(StringPiece self, StringPiece s, size_t pos) {
        if (self.size() == 0 || s.size() == 0)
            return StringPiece::npos;

        // Avoid the cost of BuildLookupTable() for a single-character search.
        if (s.size() == 1)
            return self.find(s.data()[0], pos);

        bool lookup[UCHAR_MAX + 1] = {false};
        BuildLookupTable(s, lookup);
        for (size_t i = pos; i < self.size(); ++i) {
            if (lookup[static_cast<unsigned char>(self.data()[i])]) {
                return i;
            }
        }
        return StringPiece::npos;
    }

// Generic brute force version.
    template<typename T, typename CharT = typename T::value_type>
    size_t find_first_ofT(T self, T s, size_t pos) {
        // Use the faster std::find() if searching for a single character.
        typename BasicStringPiece<CharT>::const_iterator found =
                s.size() == 1 ? std::find(self.begin() + pos, self.end(), s[0])
                              : std::find_first_of(self.begin() + pos, self.end(),
                                                   s.begin(), s.end());
        if (found == self.end())
            return BasicStringPiece<CharT>::npos;
        return static_cast<size_t>(found - self.begin());
    }

    size_t find_first_of(StringPiece16 self, StringPiece16 s, size_t pos) {
        return find_first_ofT(self, s, pos);
    }

// 8-bit version using lookup table.
    size_t find_first_not_of(StringPiece self, StringPiece s, size_t pos) {
        if (pos >= self.size())
            return StringPiece::npos;

        if (s.size() == 0)
            return pos;

        // Avoid the cost of BuildLookupTable() for a single-character search.
        if (s.size() == 1)
            return self.find_first_not_of(s.data()[0], pos);

        bool lookup[UCHAR_MAX + 1] = {false};
        BuildLookupTable(s, lookup);
        for (size_t i = pos; i < self.size(); ++i) {
            if (!lookup[static_cast<unsigned char>(self.data()[i])]) {
                return i;
            }
        }
        return StringPiece::npos;
    }

// Generic brute-force version.
    template<typename T, typename CharT = typename T::value_type>
    size_t find_first_not_ofT(T self, T s, size_t pos) {
        if (self.size() == 0)
            return BasicStringPiece<CharT>::npos;

        for (size_t self_i = pos; self_i < self.size(); ++self_i) {
            bool found = false;
            for (auto c: s) {
                if (self[self_i] == c) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return self_i;
        }
        return BasicStringPiece<CharT>::npos;
    }

    size_t find_first_not_of(StringPiece16 self, StringPiece16 s, size_t pos) {
        return find_first_not_ofT(self, s, pos);
    }

// 8-bit version using lookup table.
    size_t find_last_of(StringPiece self, StringPiece s, size_t pos) {
        if (self.size() == 0 || s.size() == 0)
            return StringPiece::npos;

        // Avoid the cost of BuildLookupTable() for a single-character search.
        if (s.size() == 1)
            return self.rfind(s.data()[0], pos);

        bool lookup[UCHAR_MAX + 1] = {false};
        BuildLookupTable(s, lookup);
        for (size_t i = std::min(pos, self.size() - 1);; --i) {
            if (lookup[static_cast<unsigned char>(self.data()[i])])
                return i;
            if (i == 0)
                break;
        }
        return StringPiece::npos;
    }

// Generic brute-force version.
    template<typename T, typename CharT = typename T::value_type>
    size_t find_last_ofT(T self, T s, size_t pos) {
        if (self.size() == 0)
            return BasicStringPiece<CharT>::npos;

        for (size_t self_i = std::min(pos, self.size() - 1);;
             --self_i) {
            for (auto c: s) {
                if (self.data()[self_i] == c)
                    return self_i;
            }
            if (self_i == 0)
                break;
        }
        return BasicStringPiece<CharT>::npos;
    }

    size_t find_last_of(StringPiece16 self, StringPiece16 s, size_t pos) {
        return find_last_ofT(self, s, pos);
    }

// 8-bit version using lookup table.
    size_t find_last_not_of(StringPiece self, StringPiece s, size_t pos) {
        if (self.size() == 0)
            return StringPiece::npos;

        size_t i = std::min(pos, self.size() - 1);
        if (s.size() == 0)
            return i;

        // Avoid the cost of BuildLookupTable() for a single-character search.
        if (s.size() == 1)
            return self.find_last_not_of(s.data()[0], pos);

        bool lookup[UCHAR_MAX + 1] = {false};
        BuildLookupTable(s, lookup);
        for (;; --i) {
            if (!lookup[static_cast<unsigned char>(self.data()[i])])
                return i;
            if (i == 0)
                break;
        }
        return StringPiece::npos;
    }

// Generic brute-force version.
    template<typename T, typename CharT = typename T::value_type>
    size_t find_last_not_ofT(T self, T s, size_t pos) {
        if (self.size() == 0)
            return StringPiece::npos;

        for (size_t self_i = std::min(pos, self.size() - 1);; --self_i) {
            bool found = false;
            for (auto c: s) {
                if (self.data()[self_i] == c) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return self_i;
            if (self_i == 0)
                break;
        }
        return BasicStringPiece<CharT>::npos;
    }

    size_t find_last_not_of(StringPiece16 self, StringPiece16 s, size_t pos) {
        return find_last_not_ofT(self, s, pos);
    }

    size_t find(WStringPiece self, WStringPiece s, size_t pos) {
        return findT(self, s, pos);
    }

    size_t rfind(WStringPiece self, WStringPiece s, size_t pos) {
        return rfindT(self, s, pos);
    }

    size_t find_first_of(WStringPiece self, WStringPiece s, size_t pos) {
        return find_first_ofT(self, s, pos);
    }

    size_t find_first_not_of(WStringPiece self, WStringPiece s, size_t pos) {
        return find_first_not_ofT(self, s, pos);
    }

    size_t find_last_of(WStringPiece self, WStringPiece s, size_t pos) {
        return find_last_ofT(self, s, pos);
    }

    size_t find_last_not_of(WStringPiece self, WStringPiece s, size_t pos) {
        return find_last_not_ofT(self, s, pos);
    }
}

bool UTF16ToUTF8(const char16_t *src, size_t src_len, std::string *output) {
    StringPiece16(src, src_len);
    return true;
}

#endif //CPPSTUDY_STRING_DEFINITION_H
