//approch - 1 ->  T.c = O(n^2)

//travel each place until we get the circuler loop

//approch - 2
//having a start symbol and moving forward until we get a location from where we can move till end
//deficient + balance >=0 it mans we can travel the whole circle..

//code - 1

// int tour(petrolPump p[],int n)
// {
//     //Your code here
//     int bal =0;
//     int front = 0;
//     int rear = 0;
//     int kami=0;
//     for(int i=0; i< n; i++){
//         int pet = p[i].petrol;
//         int dis = p[i].distance;
//         //if we have balance to move next location
//         if( (bal+pet-dis) >= 0 ){
//             bal = bal+pet-dis;
//             rear++;
//         }
        
//         else{
//             kami += dis-pet-bal; // addition of all neg balance we need
//             front = rear+1;
//             rear = front;
//             bal=0;
//         }
//     }
    
//     if(bal >= kami){
//         return front;
//     }
//     return -1;
// }

//code - 2 same as upper 

// int tour(petrolPump p[],int n)
// {
//     //Your code here
//     int start = 0;
//     int balance = 0;
//     int kami = 0;
//     for(int i=0;i<n;i++)
//     {
//         balance += p[i].petrol-p[i].distance;
//         if(balance < 0)
//         {
//             kami += balance;
//             start = i+1;
//             balance = 0;
//         }
//     }
//     if(kami + balance >= 0)
//     return start;
//     return -1;
// }