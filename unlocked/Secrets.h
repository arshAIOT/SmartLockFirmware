#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "UnlockedEsp1"                         //change this
 
const char WIFI_SSID[] = "VIRGIN032";               //change this
const char WIFI_PASSWORD[] = "77D2E14E79FE";           //change this
const char AWS_IOT_ENDPOINT[] = "a10rwbwenh6tuv-ats.iot.us-east-2.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUQBLctCbZJ88qcBD+uHzRHDyyOkowDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDYwNzIyNDcx
NloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKSRj/t6t9i2Uk76P+H8
W7GIdGG2iMV2x0w8IWkU8MNT/0H9gZJf44MqeGcwh3t2INP3Hr05RX03/W7ZQjwg
Yv8J2TO05HobAMei6lGQgeLSS+92ArIfEbNvYsF8BHswZeLfDOD90erDD5dCTgsd
jjSYSyJ0Bo1kQ6Emod4ndq24vkF3PXMAmTjeuEToBVUyCRpyEBt9fl+2BHXkH9Cp
pFfozNRi5Pr74obo8bFgkfWFAz26qdBtMVhTc5H/iToIbdK1kkFVvSGrD6R+6Npx
tNFwVBuVVAPz0qyddbV7SKS51nv/Xk2WDFxou4QMWhS8VG1mGaovYSYqygEdl4QN
OTsCAwEAAaNgMF4wHwYDVR0jBBgwFoAU/y1p3kNAPbtXuoLqSNaL7isZYeowHQYD
VR0OBBYEFHG8QeA5e2X5OcM8wbnzmDwaxn5wMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQB8yKwL44lPrBV41DsAQu4XhEYQ
HWA7kv9vEHQfaKiKs8P8a1nlHyU9iHnlmFhXKET425Uvf7SD0j5WJYWuH6UxBP90
vCOopy56LMxrlBlfXwxZyXpMUMLAl69T8bUQwVDAYzzblojYURtCdsbPTzzxl/11
y4aT4uVpeq56iX7VjmB6D9Zch0RUxUoH2tArqz/rNF22noMfZdmn0PtUCyNrX74M
cPCQikqKAs8XhhBG7uW5ocEKoUp/iav4zOkeg/ezBc8TWCD65urQbH+9UhomOhuD
xaNxkD3lHnaISEjoBGalWrYiw/dHdvYoKKEbHnCGJJmxs9GFLV6JfIyadpdg
-----END CERTIFICATE-----


)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEApJGP+3q32LZSTvo/4fxbsYh0YbaIxXbHTDwhaRTww1P/Qf2B
kl/jgyp4ZzCHe3Yg0/cevTlFfTf9btlCPCBi/wnZM7TkehsAx6LqUZCB4tJL73YC
sh8Rs29iwXwEezBl4t8M4P3R6sMPl0JOCx2ONJhLInQGjWRDoSah3id2rbi+QXc9
cwCZON64ROgFVTIJGnIQG31+X7YEdeQf0KmkV+jM1GLk+vvihujxsWCR9YUDPbqp
0G0xWFNzkf+JOght0rWSQVW9IasPpH7o2nG00XBUG5VUA/PSrJ11tXtIpLnWe/9e
TZYMXGi7hAxaFLxUbWYZqi9hJirKAR2XhA05OwIDAQABAoIBAQCQQQRL9UNIVHEL
x7LNve8GTM1vhZiYNsj2G1NSEEgHgA6lYrj8fM8qf8Tw9wobf+3Av8KTLauq2rRt
QUYc/GqqkpBxEaShICBr3nO1MY2ZLKvhaLluN2vFtOKFJderwD3fQ5O/eN5UAc4d
0cIlXi/0DHb36WqA8B2UGhATctZF6d2R0jYQCEWt0TuO8Ql2lFDdwRopfHb+NjHH
YS4NaXlqFYsOvG6to2yUYA3S8x3fYU/dR8TtmepEui5Cr7LfKpjGr2BGBhcGvN33
hw3+JlkxA+V7hN3dF2eRi6b6muBjlPxHF3P1UfJNOOLv+b47k/DH+zG4RLmMV5JE
KEKt1tA5AoGBANghSMXKvKqt9YmtfHbNXo4w5CC12+UNmQcQqPB9EgcsOnQUGIjK
cvkIkGAaGQhGR0wsZW8/iNdbcp0zw/D1zW9uZUSyRUqVMd0axUYWK9QpTHVsKigU
cFiAqDl6JTAI1mYkpQebAR6Ty6oYpvngEgc59WNWK4b3jt9lonVazAUtAoGBAMLt
S9SS+ejo08/9AeDyXivF3T1P/R6wlegXg4oiTa0U3plCTyhd/1Gn0ny7Jxw6JaHc
sUgAAXAwyr0dbN6vbuDis7osqdmq995X/Q11RBo50xD8Ys9X2g0JoDK7+xuY2PsG
Wi2SUrpe6ysKDxHwSYuRI17OBGNJxiVZ7Br5BIkHAoGBALCNgAUTOEu1D38IWUQz
P6qoBbMy3A6grQE4esj5YmC5oIZyZBhaSNFmTYozx38a6eMv4SyfmglSiq4gO0/7
e3YrmE4l0rS6a6FS3RQDyInnsq25Tjave5bQgptxTC+RCJMoHCe6V4/C6/xnZv94
K0H79pjPK391eyDCxZNYOJGBAoGBAJpJOskx4G8SwnyQ9Qi4rgMVpOzfwCineq/u
1KXkSvkhWKOUEZWQ+QMHw5oIhIdaGulIBmZH4tuLMx2HCeIkl62Wos1MhtAL/A9Y
M6qQU+wyMrbyHb+h+KxzHwKpObN5Qt1GBOCnPaXYdWlml9EKERxQL9/dTynLffOY
fkJHMejHAoGAfg/Hb6uBYgNv9UhqBfPoVtgf8+OPgIIh3ZFdRClVJ8Rn2fOplO5C
x8qvDia38IvkV11ZY+q2XfZoFS1o9jt4YnpvRPJIDsFl7chxw066K3sJzz2GxCaK
vwjhIQinSckwaUXT+CVPVLYPfEZRVDfBkFq3gbAs7jMewpdWph0rNag=
-----END RSA PRIVATE KEY-----

 
 
)KEY";