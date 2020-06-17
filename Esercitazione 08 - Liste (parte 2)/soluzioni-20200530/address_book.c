#include <stdlib.h> 
#include <string.h> 

#include "list_address.h" 

const ElemType* Find(const Item* i, const char *name) {
    const Item *tmp = i;
    while (!IsEmptyList(tmp)) {
        if (strcmp(tmp->value.name, name) == 0) {
            return &tmp->value;
        }
        tmp = GetTailList(tmp);
    }
    return NULL;
}

Item* Delete(Item* i, const char *name)
{
    Item *new_list = CreateEmptyList();
    Item *tmp = i;
    while (!IsEmptyList(tmp)) {
        if (strcmp(tmp->value.name, name) != 0) {
            new_list = InsertBackList(new_list, &tmp->value);
        }
        tmp = GetTailList(tmp);
    }
    DeleteList(i);
    return new_list;
}

void Swap(Item *a, Item *b) {
    ElemType tmp = b->value;
    b->value = a->value;
    a->value = tmp;
}

// -> 1 -> 3 -> 4
// 
Item* Sort(Item* i) {
    Item *tmp_a = i;
    while (!IsEmptyList(tmp_a)) {
        Item *tmp_b = tmp_a->next;
        while (!IsEmptyList(tmp_b)) {
            if (ElemCompare(GetHeadValueList(tmp_a), GetHeadValueList(tmp_b)) > 0) {
                Swap(tmp_a, tmp_b);
            }
            tmp_b = GetTailList(tmp_b);
        }
        tmp_a = GetTailList(tmp_a);
    }
    return i;
}

Item* Filtra(Item* i, const char *city) {
    Item *new_list = CreateEmptyList();
    Item *tmp = i;
    while (!IsEmptyList(tmp)) {
        if (strcmp(tmp->value.city, city) == 0) {
            new_list = InsertBackList(new_list, &tmp->value);
        }
        tmp = GetTailList(tmp);
    }
    return new_list;
}

Item* Reverse(const Item* i) {
    Item *new_list = CreateEmptyList();
    const Item *tmp = i;
    while (!IsEmptyList(tmp)) {
        new_list = InsertHeadList(&tmp->value, new_list);
        tmp = GetTailList(tmp);
    }
    return new_list;
}

Item* Append(const Item* i1, const Item* i2) {
    Item *new_list = CreateEmptyList();
    const Item *tmp = i1;
    while (!IsEmptyList(tmp)) {
        new_list = InsertBackList(new_list, &tmp->value);
        tmp = GetTailList(tmp);
    }

    tmp = i2;
    while (!IsEmptyList(tmp)) {
        new_list = InsertBackList(new_list, &tmp->value);
        tmp = GetTailList(tmp);
    }

    return new_list;
}

Item* AppendMod(Item* i1, Item* i2)
{
    if (IsEmptyList(i2)) {
        return i2;
    }

    Item *tmp = i1;
    while (!IsEmptyList(GetTailList(tmp))) {
        tmp = GetTailList(tmp);
    }

    tmp->next = i2;
    return i1;
}


int main(void)
{
    ElemType e1 = { "Federico", "Peschiera", 54, "Modena", "MO", "41126" };
    ElemType e2 = { "Michele", "Firenze", 12, "Modena", "MO", "41126" };
    ElemType e3 = { "Massimiliano", "Roma", 23, "Firenze", "FI", "50100" };
    ElemType e4 = { "Stefano", "Venezia", 10, "Milano", "MI", "20019" };

    Item *ab = CreateEmptyList();
    ab = InsertBackList(ab, &e1);
    ab = InsertBackList(ab, &e2);
    ab = InsertBackList(ab, &e3);
    ab = InsertBackList(ab, &e4);

    const ElemType *found_1 = Find(ab, "Federico");
    const ElemType *found_2 = Find(ab, "Elena");

    ab = Delete(ab, "Elena");
    ab = Delete(ab, "Federico");

    ab = Sort(ab);
    Item * new_modena = Filtra(ab, "Modena");
    Item * new_milano = Filtra(ab, "Milano");

    Item * reverse = Reverse(ab);

    Item * append_1 = Append(CreateEmptyList(), ab);
    Item * append_2 = Append(ab, CreateEmptyList());
    Item * append_3 = Append(ab, reverse);

    Item * append_mod = AppendMod(ab, reverse);

    WriteStdoutList(append_mod);

    DeleteList(new_modena);
    DeleteList(new_milano);
    DeleteList(append_1);
    DeleteList(append_2);
    DeleteList(append_3);

    DeleteList(append_mod);

    return EXIT_SUCCESS;
}