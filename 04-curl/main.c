#include <stdio.h>
#include <curl/curl.h>

int main (void) {
    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();

    if(curl == NULL) {
        fprintf(stderr, "HTTP request faild\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
    result = curl_easy_perform(curl);

    if(result != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return -1;
    }


    
    return 0;
}