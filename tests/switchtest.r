x <- 1

for (x in 1:6) {
  switch(x,
    {
      print(1)
      print(2)
    },
    {
      print(2)
      print(3)
    },
    {
      print(3)
      print(4)
    },
    {
      print(4)
      print(5)
    },
    {
      print(5)
      print(6)
    },
  )
}
