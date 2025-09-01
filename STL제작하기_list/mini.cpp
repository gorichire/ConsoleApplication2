#pragma once
#include <cstddef>
#include <cassert>

// 교육용 mini::list — Step 1
// - 이중 연결 리스트 + 양방향 반복자
// - 기능: size/empty, begin/end, front/back, push_front/push_back,
//         insert(pos, value), erase(pos), clear, destructor
// - 예외/복사/이동은 최소화(학습용)

namespace mini {

    template <class T>
    class list {
    private:
        struct node {
            T     value;
            node* prev;
            node* next;
            node(const T& v, node* p = nullptr, node* n = nullptr)
                : value(v), prev(p), next(n) {}
        };

        node* head_;   // 더미(head) — 첫 요소는 head_->next
        node* tail_;   // 더미(tail) — 끝은 tail_ (마지막 요소는 tail_->prev)
        std::size_t sz_;

    public:
        class iterator {
            friend class list;
            node* cur_{};
            explicit iterator(node* p) : cur_(p) {}
        public:
            using value_type = T;
            using reference = T&;
            using pointer = T*;

            iterator() = default;
            reference operator*() const { return cur_->value; }
            pointer   operator->() const { return &cur_->value; }

            iterator& operator++() { cur_ = cur_->next; return *this; }      // pre++
            iterator& operator--() { cur_ = cur_->prev; return *this; }      // pre--

            bool operator==(const iterator& o) const { return cur_ == o.cur_; }
            bool operator!=(const iterator& o) const { return cur_ != o.cur_; }
        };

        class const_iterator {
            friend class list;
            const node* cur_{};
            explicit const_iterator(const node* p) : cur_(p) {}
        public:
            using value_type = T;
            using reference = const T&;
            using pointer = const T*;

            const_iterator() = default;
            reference operator*() const { return cur_->value; }
            pointer   operator->() const { return &cur_->value; }

            const_iterator& operator++() { cur_ = cur_->next; return *this; }
            const_iterator& operator--() { cur_ = cur_->prev; return *this; }

            bool operator==(const const_iterator& o) const { return cur_ == o.cur_; }
            bool operator!=(const const_iterator& o) const { return cur_ != o.cur_; }

            // 비-const iterator로의 변환자 제공
            operator iterator() const { return iterator(const_cast<node*>(cur_)); }
        };

        // 기본 생성/소멸
        list() : head_(new node(T{})), tail_(new node(T{})), sz_(0) {
            head_->next = tail_;
            tail_->prev = head_;
            head_->prev = nullptr;
            tail_->next = nullptr;
        }

        ~list() {
            clear();
            delete head_;
            delete tail_;
            head_ = tail_ = nullptr;
        }

        // 복사/이동은 Step 2에서.. (학습 단순화를 위해 금지)
        list(const list&) = delete;
        list& operator=(const list&) = delete;
        list(list&&) = delete;
        list& operator=(list&&) = delete;

        // 기본 정보
        std::size_t size() const noexcept { return sz_; }
        bool empty() const noexcept { return sz_ == 0; }

        // 반복자
        iterator begin() noexcept { return iterator(head_->next); }
        iterator end()   noexcept { return iterator(tail_); }
        const_iterator begin() const noexcept { return const_iterator(head_->next); }
        const_iterator end()   const noexcept { return const_iterator(tail_); }
        const_iterator cbegin() const noexcept { return const_iterator(head_->next); }
        const_iterator cend()   const noexcept { return const_iterator(tail_); }

        // 접근자
        T& front() { assert(sz_ > 0); return head_->next->value; }
        const T& front() const { assert(sz_ > 0); return head_->next->value; }
        T& back() { assert(sz_ > 0); return tail_->prev->value; }
        const T& back() const { assert(sz_ > 0); return tail_->prev->value; }

        // 수정자
        void clear() noexcept {
            node* p = head_->next;
            while (p != tail_) {
                node* nxt = p->next;
                delete p;
                p = nxt;
            }
            head_->next = tail_;
            tail_->prev = head_;
            sz_ = 0;
        }

        void push_front(const T& v) { insert(begin(), v); }
        void push_back(const T& v) { insert(end(), v); }

        // pos 앞(before pos)에 새 노드 삽입, 새 위치 반복자 반환
        iterator insert(iterator pos, const T& v) {
            node* p = pos.cur_;
            node* n = new node(v);
            node* L = p->prev;  // left neighbor

            n->prev = L; n->next = p;
            L->next = n; p->prev = n;
            ++sz_;
            return iterator(n);
        }

        // pos 위치 노드 제거, 다음 위치 반복자 반환
        iterator erase(iterator pos) {
            node* p = pos.cur_;
            assert(p != head_ && p != tail_); // 더미는 지우지 않음
            node* L = p->prev;
            node* R = p->next;
            L->next = R; R->prev = L;
            delete p;
            --sz_;
            return iterator(R);
        }
    };

}  namespace mini
