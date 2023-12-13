//20301125
//Task 1 in Struct and Functions


#include <stdio.h>

struct Item {
    int quantity;
    float unit_price;
};

int main() {
    struct Item paratha, vegetable, mineral_water;
    int num_people;

    printf("Quantity of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity of Vegetable: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);

    printf("Quantity of Mineral Water: ");
    scanf("%d", &mineral_water.quantity);
    printf("Unit Price: ");
    scanf("%f", &mineral_water.unit_price);

    printf("Number of People: ");
    scanf("%d", &num_people);
    float total_bill = (paratha.quantity * paratha.unit_price) +
                       (vegetable.quantity * vegetable.unit_price) +
                       (mineral_water.quantity * mineral_water.unit_price);
    float individual_payment = total_bill / num_people;
    printf("Individual people will pay: %.2f tk\n", individual_payment);
    return 0;
}
