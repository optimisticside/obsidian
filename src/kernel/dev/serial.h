#ifndef DEV_SERIAL_H
#define DEV_SERIAL_H

/*
 * Serial port defenitions
 */
#define COM1	0x3F8
#define COM2	0x2F8
#define COM3	0x3E8
#define COM4	0x2E8

int	serial_recieved(uint16_t port);
int	serial_check(uint16_t port);
char	serial_read(uint16_t port);
int	serial_write(uint16_t port, char ch);

#endif /* DEV_SERIAL_H */
