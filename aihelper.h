// aihelper.h
#include <QObject>
#include <QString>

class AIHelper : public QObject
{
    Q_OBJECT
public:
    explicit AIHelper(QObject *parent = nullptr);
    QString detectThemeFromAI(const QString &description);
    QString enhanceDescriptionWithAI(const QString &description);

private:
    QString apiKey;
    QString callHuggingFaceAPI(const QString &url, const QJsonObject &jsonData);
};
