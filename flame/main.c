#include <stdio.h>
#include <math.h>

int main (void)
{
    
    double heatRR, flameHt;
    int wall_E, try, unit;
    char ch;
    
    /* Choose which entity to calculate */
    printf("Do you wish to calculate (a) heat release rate or (b) flame height? ");
    scanf("%c", &ch);
    if (ch == 'a')
    {
        /* Loop to perform defensive programming: checking user input for flame 
		 height. User enters 1 or 2 for metres or feet, and a value for the flame 
		 height. If the flame height is less than zero, an error message ensues,
		 and the loop cycles. Five attempts are allowed. */
        try = 0;
        while(try < 5)
        {
            printf("(1) Metres or (2) Feet ?");
            scanf("%d", &unit);
            printf("Enter the flame height: ");
            scanf("%lf", &flameHt);
            if (flameHt <= 0.0)
                printf("No fire exists... maybe smoke?\n");
            else
                break;
            try = try + 1;
        }        
        
        /* Loop to perform defensive programming: checking user input for the wall
		 effect factor. User enters 1, 2 or 4 for the wall effect factor. If the 
		 wall effect factor is not 1/2/4 then an error message ensues, and the loop 
		 cycles. Five attempts are allowed. */
        try = 0;
        while(try < 5)
        {
            printf("Enter the wall effect factor (Choose either 1, 2, or 4)\n");
            printf("1=room centre, 2=wall, 4=corner:");
            scanf("%d", &wall_E);
            
            if (wall_E != 1 && wall_E != 2 && wall_E != 4)
                printf("Wrong wall effect factor\n");
            else
                break;
            try = try + 1;
        }
        
        if (unit == 1)
            heatRR = (79.18 * pow(flameHt,2.5)) / wall_E;
        else if (unit == 2)
            heatRR = (79.18 * pow(flameHt/3.33,2.5)) / wall_E;
        
        
        printf("Heat release rate for a flame of height %.2fm = %.2f kilowatts\n", flameHt, heatRR);
        
    }
    else if (ch == 'b')
    {
		try = 0;
        while(try < 5)
        {
            printf("Enter the heat release rate (w): ");
            scanf("%lf", &heatRR);
            if (heatRR <= 0.0)
                printf("There is no heat\n");
            else
                break;
            try = try + 1;
        }        
        
        try = 0;
        while(try < 5)
        {
            printf("Enter the wall effect factor (Choose either 1, 2, or 4)\n");
            printf("1=room centre, 2=wall, 4=corner:");
            scanf("%d", &wall_E);
            
            if (wall_E != 1 && wall_E != 2 && wall_E != 4)
                printf("Wrong wall effect factor\n");
            else
                break;
            try = try + 1;
        }
        
        flameHt = 0.174 * pow(wall_E * heatRR,0.4);
        
        printf("The flame height is %.2f m\n", flameHt);
		
    }
    
    return 0;
}
