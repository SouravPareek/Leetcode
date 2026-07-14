//self
class BrowserHistory {
public:
    struct ListNode {
        string url;
        ListNode* prev;
        ListNode* next;

        ListNode(string data) {
            url = data;
            prev = nullptr;
            next = nullptr;
        }
    };

    ListNode* page;

    BrowserHistory(string homepage) {
        this->page = new ListNode(homepage);
    }

    void visit(string url) {
        ListNode* node = new ListNode(url);
        page->next = node;
        node->prev = page;
        page = node;
    }

    string back(int steps) {
        while (steps-- > 0 && page->prev)
            page = page->prev;

        return page->url;
    }

    string forward(int steps) {
        while (steps-- > 0 && page->next)
            page = page->next;

        return page->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */