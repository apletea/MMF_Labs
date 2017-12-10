import pandas
import os
from sets import  Set
import pickle
from sklearn.gaussian_process import GaussianProcessClassifier
from sklearn.model_selection import train_test_split
from sklearn import svm
from sklearn import preprocessing
from sklearn.neural_network import MLPClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
from sklearn.naive_bayes import GaussianNB
from sklearn.gaussian_process.kernels import RBF
from sklearn.metrics import roc_curve,roc_auc_score

from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier

labeled_data = pandas.read_csv('train.csv', index_col='Id')
train_img_data = pandas.read_csv('img_train.csv', index_col='Id')
test_data = pandas.read_csv('test.csv',index_col='Id')
test_img_data = pandas.read_csv('img_test.csv',index_col='Id')

def abra_cadabra(parameter, data, data2):
    something = Set()
    something_a= []
    for val in data[parameter]:
        something.add(val)
        something_a.append(val)
    something_b = []
    for val in data2[parameter]:
        something.add(val)
        something_b.append(val)
    something_le = preprocessing.LabelEncoder()
    something_le.fit(list(something))
    something_a = something_le.transform(something_a)
    something_b = something_le.transform(something_b)
    return something_a,something_b



languages_a, languages_b = abra_cadabra('Language',labeled_data, test_data)
countries_a, countries_b = abra_cadabra('Country',labeled_data, test_data)
ratings_a , ratings_b = abra_cadabra('Rating',labeled_data, test_data)



labeled_data['Language'],labeled_data['Country'],labeled_data['Rating'] = languages_a,countries_a,ratings_a
test_data['Language'],test_data['Country'],test_data['Rating'] = languages_b,countries_b,ratings_b
data = labeled_data.iloc[:, 1:27]
data['Poster'] = train_img_data['Prob']
test_data['Poster'] = test_img_data['Prob']
#print test_data
#data = preprocessing.scale(data)
labels = labeled_data.iloc[:, :1]

#clf = MLPClassifier(activation='relu',batch_size=255)
#clf = DecisionTreeClassifier(random_state=247)
#clf = svm.SVC(random_state=247, kernel='rbf')
#clf = QuadraticDiscriminantAnalysis()
#clf = GaussianProcessClassifier(1.0 * RBF(1.0), warm_start=True)
clf = GradientBoostingClassifier(n_estimators=100, learning_rate=.45, max_depth=1, random_state=247)
clf.fit(data,labels.values.ravel())


print clf.predict_proba(test_data)[:,1:]
#print clf.predict_proba(test_data)
print clf.predict(test_data)
#print roc_auc_score(test_labeles,clf.predict(test_data))

res =1- clf.predict_proba(test_data)[:,:1]
df = pandas.DataFrame(res)
df.index.name = 'Id'
df.index +=3636
df.columns=['Probability']
df.to_csv('results.csv',header=True)