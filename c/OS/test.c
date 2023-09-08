extern int share;

int main(int argc, char *argv[]) {
  int a = 1;
  swap(a, share);
  return 0;
}
