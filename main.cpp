#include <cstdlib>
#include <drogon/drogon.h>
#include <string>
#include <iostream>

using namespace std;
using namespace drogon;

extern double calculateBMI(double weight, double height);

void bmiHandler(const HttpRequestPtr &request,
                function<void(const HttpResponsePtr &)> &&callback,
                double weight,
                double height) {

    Json::Value jsonBody;

    try {
        double bmi = calculateBMI(weight, height);
        jsonBody["status"] = "success";
        jsonBody["weight"] = weight;
        jsonBody["height"] = height;
        jsonBody["IMT"] = bmi;

        auto response = HttpResponse::newHttpJsonResponse(jsonBody);
        response->setStatusCode(k200OK);
        callback(response);

    } catch (const invalid_argument& e) {
        jsonBody["status"] = "error";
        jsonBody["error"] = e.what();
        auto response = HttpResponse::newHttpJsonResponse(jsonBody);
        response->setStatusCode(k400BadRequest);
        callback(response);
    }
}

int main() {
    cout << "  IMT REST API Server" << endl;
    cout << "  Server is running" << endl;

    app()
        .loadConfigFile("./config.json")
        .registerHandler("/api/bmi/{weight}/{height}",
                         &bmiHandler,
                         {Get})
        .run();

    return EXIT_SUCCESS;
}
