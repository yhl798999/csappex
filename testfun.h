#ifndef TESTFUN_H
#define TESTFUN_H

void to_upper(char*str, int len);
void to_lower(char*str, int len);

// 读第一行，以获知转换为大写还是小写 upper : 大写， lower : 小写
// 从第二行开始转换，遇到空行即停止
void transform(int fd);

#endif // TESTFUN_H