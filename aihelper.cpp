#include "aihelper.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

const QString NLP_MODEL_URL = "https://api-inference.huggingface.co/models/facebook/bart-large-mnli";
const QString GENERATION_MODEL_URL = "https://api-inference.huggingface.co/models/mistralai/Mistral-7B-Instruct-v0.1"; // Meilleur modèle

AIHelper::AIHelper(QObject *parent) : QObject(parent)
{
    apiKey = "Bearer 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";
}

QString AIHelper::callHuggingFaceAPI(const QString &url, const QJsonObject &jsonData)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", apiKey.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, QJsonDocument(jsonData).toJson());

    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error()) {
        qDebug() << "API Error:" << reply->errorString();
        return QString();
    }

    return reply->readAll();
}

QString AIHelper::detectThemeFromAI(const QString &description)
{
    if (description.isEmpty()) return "inconnu";

    QJsonObject json;
    json["inputs"] = description;
    json["parameters"] = QJsonObject{
        {"candidate_labels", QJsonArray{"technologie", "santé", "art", "éducation"}},
        {"multi_label", false}
    };

    QString response = callHuggingFaceAPI(NLP_MODEL_URL, json);
    if (response.isEmpty()) return "inconnu";

    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
    QJsonObject result = doc.object();

    // On récupère le label avec le score le plus élevé
    QJsonArray labels = result["labels"].toArray();
    QJsonArray scores = result["scores"].toArray();

    if (labels.isEmpty() || scores.isEmpty()) return "inconnu";

    int bestIndex = 0;
    double bestScore = 0;
    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i].toDouble() > bestScore) {
            bestScore = scores[i].toDouble();
            bestIndex = i;
        }
    }

    return labels[bestIndex].toString();
}

QString AIHelper::enhanceDescriptionWithAI(const QString &description)
{
    if (description.isEmpty()) return description;

    QString prompt = QString("Améliore cette description d'événement pour un flyer attractif en 3-4 phrases maximum. "
                             "Garde un ton professionnel et engageant. Description originale: %1").arg(description);

    QJsonObject json;
    json["inputs"] = prompt;
    json["parameters"] = QJsonObject{
        {"max_new_tokens", 150},
        {"temperature", 0.7},
        {"do_sample", true}
    };

    QString response = callHuggingFaceAPI(GENERATION_MODEL_URL, json);
    if (response.isEmpty()) return description;

    // Nettoyer la réponse en supprimant le prompt si présent
    QString result = response.trimmed();
    if (result.startsWith(prompt)) {
        result = result.mid(prompt.length()).trimmed();
    }

    return result.isEmpty() ? description : result;
}
