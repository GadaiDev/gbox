#include <stdio.h>
#include <curl/curl.h>

// Callback function to write the received data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    // Initialize cURL
    CURL *curl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // URL of the binary file to download
        const char *url = "https://gadaidev.github.io/gbox/gbox";

        // Open a file to write the downloaded data
        FILE *fp = fopen("gbox", "wb");
        if (fp == NULL) {
            fprintf(stderr, "Error opening the file for writing\n");
            return 1;
        }

        // Set the cURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the cURL operation
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "cURL failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
        fclose(fp);

        // Cleanup cURL global state
        curl_global_cleanup();

        return 0;
    } else {
        fprintf(stderr, "cURL initialization failed\n");
        return 1;
    }
}
