/*
  vector<int> v1 = {3, 1, 7, 9};
  vector<int> v2 = {10, 2, 7, 16, 9};

  //  access v1 and v2 by reference
  auto pushinto = [&] (int m)
  {
      v1.push_back(m);
      v2.push_back(m);
  };

  // if you want access by value:
  auto smt = [=] (int m) // equal sign
  {
      v1.push_back(m);
      v2.push_back(m);
  };

  // or you can specify directly for each variable:
  auto pushinto = [&v1, v2] (int m)
  {
      v1.push_back(m);
      v2.push_back(m);
  };
*/
