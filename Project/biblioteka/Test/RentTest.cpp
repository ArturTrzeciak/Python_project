 #include <boost/test/unit_test.hpp>
 #include <vector>
 #include <algorithm>
 #include "Rent.h"
 #include "Client.h"
 #include "Vehicle.h"

 using namespace std;

 //TO DO 4

 BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

 BOOST_AUTO_TEST_CASE(TC1){
 	BOOST_CHECK_THROW(Rent(nullptr,nullptr), invalid_argument);
 }

 BOOST_AUTO_TEST_CASE(T2) {
     vector<Rent> R;
     Client* client = new Client("A","B","C");
     Vehicle* vehicle = new Vehicle("A", 2);

     for(int i=10; i-->0;){
         Rent rent(client, vehicle);
         R.push_back(rent);
     }

     vector<string> UUID;
     for(int i=10; i-->0;){
         string info = R.back().rentInfo();
         R.pop_back();

         string uuid;
         for(int p=0; info[p]!=' '; p++){
             uuid+=info[p];
         }
         UUID.push_back(uuid);
     }
     sort(UUID.begin(), UUID.end());

     for(int i=1; i<10; i++){
         BOOST_CHECK(UUID[i-1]!=UUID[i]);
     }

 }

     BOOST_AUTO_TEST_CASE(T3){
         Client *c=new Client("A","B","C");
         Vehicle *v=new Vehicle("A", 2);
         Rent R(c,v);
         BOOST_CHECK_EQUAL(R.rentDuration(), 0);
     }


     BOOST_AUTO_TEST_CASE(T4){
         Client *c=new Client("A","B","C");
         Vehicle *v=new Vehicle("A", 2);
         Rent R1(c,v);
         R1.endRent();
         //jak samemu zmienic czas oddania?

     }

     BOOST_AUTO_TEST_CASE(T5){
         Client *c=new Client("A","B","C");
         Vehicle *v=new Vehicle("A", 2);
         Rent R(c,v);
         BOOST_CHECK_EQUAL(R.rentDuration(), 0);
     }

     BOOST_AUTO_TEST_CASE(T6){
         Client *c=new Client("A","B","C");
         Vehicle *v=new Vehicle("A", 5);
         const int CAR_COST=5;
         Rent R1(c,v);
         sleep(1);
         R1.endRent();
         BOOST_CHECK_EQUAL(CAR_COST, R1.rentCost());
     }

     BOOST_AUTO_TEST_CASE(T7){
         Client *c=new Client("A","B","C");
         Vehicle *v=new Vehicle("A", 2);
         BOOST_CHECK_NO_THROW(Rent R(c,v));
     }

 BOOST_AUTO_TEST_SUITE_END()
