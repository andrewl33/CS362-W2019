from subprocess import check_output

with open("testgreathall.txt", "w") as f:
  for i in range(1, 10000000):
    output_str = check_output(["./playdom", str(i)])
    if "great_hall" in str(output_str):
      print(i)
      f.write(i)
