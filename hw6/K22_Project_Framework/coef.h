#define Korder 110 
float A1[Korder][2] = { 
{0.155701, 0.708982} ,
{-0.155701, 0.708982} ,
{-0.455981, 0.724761} ,
{0.455981, 0.724761} ,
{0.726612, 0.751596} ,
{-0.726612, 0.751596} ,
{0.957598, 0.783175} ,
{-0.957598, 0.783175} ,
{1.147351, 0.814522} ,
{-1.147351, 0.814522} ,
{1.299663, 0.842882} ,
{-1.299663, 0.842882} ,
{-1.420559, 0.867251} ,
{1.420559, 0.867251} ,
{1.516252, 0.887624} ,
{-1.516252, 0.887624} ,
{-1.592204, 0.904438} ,
{1.592204, 0.904438} ,
{1.652856, 0.918255} ,
{-1.652856, 0.918255} ,
{-1.701674, 0.929621} ,
{1.701674, 0.929621} ,
{-1.741314, 0.939006} ,
{1.741314, 0.939006} ,
{1.773794, 0.946800} ,
{-1.773794, 0.946800} ,
{-1.800647, 0.953313} ,
{1.800647, 0.953313} ,
{-1.823039, 0.958794} ,
{1.823039, 0.958794} ,
{1.841866, 0.963438} ,
{-1.841866, 0.963438} ,
{1.857817, 0.967399} ,
{-1.857817, 0.967399} ,
{1.871430, 0.970800} ,
{-1.871430, 0.970800} ,
{1.883126, 0.973739} ,
{-1.883126, 0.973739} ,
{-1.893238, 0.976293} ,
{1.893238, 0.976293} ,
{1.902031, 0.978526} ,
{-1.902031, 0.978526} ,
{1.909719, 0.980489} ,
{-1.909719, 0.980489} ,
{-1.916475, 0.982222} ,
{1.916475, 0.982222} ,
{1.922438, 0.983761} ,
{-1.922438, 0.983761} ,
{-1.927725, 0.985134} ,
{1.927725, 0.985134} ,
{1.932431, 0.986363} ,
{-1.932431, 0.986363} ,
{-1.936635, 0.987469} ,
{1.936635, 0.987469} ,
{-1.940403, 0.988468} ,
{1.940403, 0.988468} ,
{-1.943792, 0.989374} ,
{1.943792, 0.989374} ,
{-1.946849, 0.990198} ,
{1.946849, 0.990198} ,
{1.949613, 0.990951} ,
{-1.949613, 0.990951} ,
{-1.952118, 0.991642} ,
{1.952118, 0.991642} ,
{1.954394, 0.992277} ,
{-1.954394, 0.992277} ,
{1.956467, 0.992863} ,
{-1.956467, 0.992863} ,
{1.958356, 0.993406} ,
{-1.958356, 0.993406} ,
{1.960083, 0.993911} ,
{-1.960083, 0.993911} ,
{-1.961662, 0.994381} ,
{1.961662, 0.994381} ,
{-1.963108, 0.994821} ,
{1.963108, 0.994821} ,
{-1.964434, 0.995234} ,
{1.964434, 0.995234} ,
{1.965650, 0.995623} ,
{-1.965650, 0.995623} ,
{-1.966766, 0.995991} ,
{1.966766, 0.995991} ,
{1.967791, 0.996339} ,
{-1.967791, 0.996339} ,
{1.968732, 0.996670} ,
{-1.968732, 0.996670} ,
{1.969596, 0.996986} ,
{-1.969596, 0.996986} ,
{1.970387, 0.997289} ,
{-1.970387, 0.997289} ,
{-1.971113, 0.997580} ,
{1.971113, 0.997580} ,
{-1.971776, 0.997860} ,
{1.971776, 0.997860} ,
{-1.972382, 0.998132} ,
{1.972382, 0.998132} ,
{1.972933, 0.998396} ,
{-1.972933, 0.998396} ,
{1.973432, 0.998653} ,
{-1.973432, 0.998653} ,
{1.973884, 0.998905} ,
{-1.973884, 0.998905} ,
{1.974288, 0.999153} ,
{-1.974288, 0.999153} ,
{1.974649, 0.999397} ,
{-1.974649, 0.999397} ,
{-1.974967, 0.999639} ,
{1.974967, 0.999639} ,
{1.975244, 0.999880} ,
{-1.975244, 0.999880} 
};

float B1[Korder][2] = { 
{0.975809, 0.175145} ,
{0.975809, -0.175145} ,
{0.975809, -0.509155} ,
{0.975809, 0.509155} ,
{0.975809, 0.801123} ,
{0.975809, -0.801123} ,
{0.975809, 1.039955} ,
{0.975809, -1.039955} ,
{0.975809, 1.227254} ,
{0.975809, -1.227254} ,
{0.975809, 1.371042} ,
{0.975809, -1.371042} ,
{0.975809, -1.480727} ,
{0.975809, 1.480727} ,
{0.975809, 1.564649} ,
{0.975809, -1.564649} ,
{0.975809, -1.629398} ,
{0.975809, 1.629398} ,
{0.975809, 1.679905} ,
{0.975809, -1.679905} ,
{0.975809, -1.719778} ,
{0.975809, 1.719778} ,
{0.975809, -1.751642} ,
{0.975809, 1.751642} ,
{0.975809, 1.777404} ,
{0.975809, -1.777404} ,
{0.975809, -1.798467} ,
{0.975809, 1.798467} ,
{0.975809, -1.815866} ,
{0.975809, 1.815866} ,
{0.975809, 1.830377} ,
{0.975809, -1.830377} ,
{0.975809, 1.842586} ,
{0.975809, -1.842586} ,
{0.975809, 1.852943} ,
{0.975809, -1.852943} ,
{0.975809, 1.861793} ,
{0.975809, -1.861793} ,
{0.975809, -1.869407} ,
{0.975809, 1.869407} ,
{0.975809, 1.875999} ,
{0.975809, -1.875999} ,
{0.975809, 1.881739} ,
{0.975809, -1.881739} ,
{0.975809, -1.886763} ,
{0.975809, 1.886763} ,
{0.975809, 1.891181} ,
{0.975809, -1.891181} ,
{0.975809, -1.895084} ,
{0.975809, 1.895084} ,
{0.975809, 1.898545} ,
{0.975809, -1.898545} ,
{0.975809, -1.901626} ,
{0.975809, 1.901626} ,
{0.975809, -1.904377} ,
{0.975809, 1.904377} ,
{0.975809, -1.906841} ,
{0.975809, 1.906841} ,
{0.975809, -1.909054} ,
{0.975809, 1.909054} ,
{0.975809, 1.911046} ,
{0.975809, -1.911046} ,
{0.975809, -1.912843} ,
{0.975809, 1.912843} ,
{0.975809, 1.914467} ,
{0.975809, -1.914467} ,
{0.975809, 1.915936} ,
{0.975809, -1.915936} ,
{0.975809, 1.917267} ,
{0.975809, -1.917267} ,
{0.975809, 1.918474} ,
{0.975809, -1.918474} ,
{0.975809, -1.919568} ,
{0.975809, 1.919568} ,
{0.975809, -1.920562} ,
{0.975809, 1.920562} ,
{0.975809, -1.921462} ,
{0.975809, 1.921462} ,
{0.975809, 1.922279} ,
{0.975809, -1.922279} ,
{0.975809, -1.923018} ,
{0.975809, 1.923018} ,
{0.975809, 1.923685} ,
{0.975809, -1.923685} ,
{0.975809, 1.924287} ,
{0.975809, -1.924287} ,
{0.975809, 1.924827} ,
{0.975809, -1.924827} ,
{0.975809, 1.925310} ,
{0.975809, -1.925310} ,
{0.975809, -1.925739} ,
{0.975809, 1.925739} ,
{0.975809, -1.926117} ,
{0.975809, 1.926117} ,
{0.975809, -1.926447} ,
{0.975809, 1.926447} ,
{0.975809, 1.926731} ,
{0.975809, -1.926731} ,
{0.975809, 1.926971} ,
{0.975809, -1.926971} ,
{0.975809, 1.927169} ,
{0.975809, -1.927169} ,
{0.975809, 1.927326} ,
{0.975809, -1.927326} ,
{0.975809, 1.927442} ,
{0.975809, -1.927442} ,
{0.975809, -1.927520} ,
{0.975809, 1.927520} ,
{0.975809, 1.927558} ,
{0.975809, -1.927558} 
};

float A2[Korder][2] = { 
{0.081310, 0.845802} ,
{-0.081310, 0.845802} ,
{-0.242279, 0.848093} ,
{0.242279, 0.848093} ,
{-0.398462, 0.852479} ,
{0.398462, 0.852479} ,
{0.547176, 0.858608} ,
{-0.547176, 0.858608} ,
{0.686387, 0.866041} ,
{-0.686387, 0.866041} ,
{0.814786, 0.874316} ,
{-0.814786, 0.874316} ,
{-0.931751, 0.883011} ,
{0.931751, 0.883011} ,
{1.037242, 0.891776} ,
{-1.037242, 0.891776} ,
{1.131653, 0.900343} ,
{-1.131653, 0.900343} ,
{1.215670, 0.908529} ,
{-1.215670, 0.908529} ,
{1.290149, 0.916219} ,
{-1.290149, 0.916219} ,
{1.356016, 0.923353} ,
{-1.356016, 0.923353} ,
{-1.414198, 0.929911} ,
{1.414198, 0.929911} ,
{-1.465581, 0.935901} ,
{1.465581, 0.935901} ,
{1.510987, 0.941350} ,
{-1.510987, 0.941350} ,
{1.551157, 0.946291} ,
{-1.551157, 0.946291} ,
{1.586750, 0.950765} ,
{-1.586750, 0.950765} ,
{-1.618346, 0.954814} ,
{1.618346, 0.954814} ,
{-1.646455, 0.958478} ,
{1.646455, 0.958478} ,
{1.671515, 0.961797} ,
{-1.671515, 0.961797} ,
{-1.693910, 0.964806} ,
{1.693910, 0.964806} ,
{-1.713969, 0.967538} ,
{1.713969, 0.967538} ,
{1.731977, 0.970023} ,
{-1.731977, 0.970023} ,
{1.748180, 0.972287} ,
{-1.748180, 0.972287} ,
{-1.762792, 0.974355} ,
{1.762792, 0.974355} ,
{1.775997, 0.976246} ,
{-1.775997, 0.976246} ,
{1.787953, 0.977981} ,
{-1.787953, 0.977981} ,
{-1.798801, 0.979576} ,
{1.798801, 0.979576} ,
{-1.808660, 0.981045} ,
{1.808660, 0.981045} ,
{-1.817635, 0.982402} ,
{1.817635, 0.982402} ,
{-1.825818, 0.983659} ,
{1.825818, 0.983659} ,
{-1.833288, 0.984825} ,
{1.833288, 0.984825} ,
{1.840117, 0.985909} ,
{-1.840117, 0.985909} ,
{-1.846366, 0.986921} ,
{1.846366, 0.986921} ,
{1.852089, 0.987867} ,
{-1.852089, 0.987867} ,
{1.857333, 0.988754} ,
{-1.857333, 0.988754} ,
{1.862142, 0.989588} ,
{-1.862142, 0.989588} ,
{1.866552, 0.990374} ,
{-1.866552, 0.990374} ,
{-1.870597, 0.991117} ,
{1.870597, 0.991117} ,
{-1.874306, 0.991821} ,
{1.874306, 0.991821} ,
{1.877704, 0.992490} ,
{-1.877704, 0.992490} ,
{1.880814, 0.993128} ,
{-1.880814, 0.993128} ,
{-1.883658, 0.993737} ,
{1.883658, 0.993737} ,
{1.886253, 0.994322} ,
{-1.886253, 0.994322} ,
{1.888616, 0.994884} ,
{-1.888616, 0.994884} ,
{1.890760, 0.995427} ,
{-1.890760, 0.995427} ,
{1.892698, 0.995952} ,
{-1.892698, 0.995952} ,
{1.894441, 0.996462} ,
{-1.894441, 0.996462} ,
{-1.895998, 0.996959} ,
{1.895998, 0.996959} ,
{1.897379, 0.997445} ,
{-1.897379, 0.997445} ,
{1.898590, 0.997922} ,
{-1.898590, 0.997922} ,
{-1.899637, 0.998391} ,
{1.899637, 0.998391} ,
{1.900526, 0.998854} ,
{-1.900526, 0.998854} ,
{1.901260, 0.999314} ,
{-1.901260, 0.999314} ,
{1.901844, 0.999772} ,
{-1.901844, 0.999772} 
};

float B2[Korder][2] = { 
{0.978468, 0.085872} ,
{0.978468, -0.085872} ,
{0.978468, -0.255587} ,
{0.978468, 0.255587} ,
{0.978468, -0.419445} ,
{0.978468, 0.419445} ,
{0.978468, 0.574259} ,
{0.978468, -0.574259} ,
{0.978468, 0.717733} ,
{0.978468, -0.717733} ,
{0.978468, 0.848530} ,
{0.978468, -0.848530} ,
{0.978468, -0.966188} ,
{0.978468, 0.966188} ,
{0.978468, 1.070932} ,
{0.978468, -1.070932} ,
{0.978468, 1.163469} ,
{0.978468, -1.163469} ,
{0.978468, 1.244795} ,
{0.978468, -1.244795} ,
{0.978468, 1.316035} ,
{0.978468, -1.316035} ,
{0.978468, 1.378339} ,
{0.978468, -1.378339} ,
{0.978468, -1.432808} ,
{0.978468, 1.432808} ,
{0.978468, -1.480458} ,
{0.978468, 1.480458} ,
{0.978468, 1.522200} ,
{0.978468, -1.522200} ,
{0.978468, 1.558836} ,
{0.978468, -1.558836} ,
{0.978468, 1.591063} ,
{0.978468, -1.591063} ,
{0.978468, -1.619482} ,
{0.978468, 1.619482} ,
{0.978468, -1.644610} ,
{0.978468, 1.644610} ,
{0.978468, 1.666888} ,
{0.978468, -1.666888} ,
{0.978468, -1.686694} ,
{0.978468, 1.686694} ,
{0.978468, -1.704349} ,
{0.978468, 1.704349} ,
{0.978468, 1.720128} ,
{0.978468, -1.720128} ,
{0.978468, 1.734265} ,
{0.978468, -1.734265} ,
{0.978468, -1.746962} ,
{0.978468, 1.746962} ,
{0.978468, 1.758391} ,
{0.978468, -1.758391} ,
{0.978468, 1.768701} ,
{0.978468, -1.768701} ,
{0.978468, -1.778019} ,
{0.978468, 1.778019} ,
{0.978468, -1.786457} ,
{0.978468, 1.786457} ,
{0.978468, -1.794109} ,
{0.978468, 1.794109} ,
{0.978468, -1.801059} ,
{0.978468, 1.801059} ,
{0.978468, -1.807378} ,
{0.978468, 1.807378} ,
{0.978468, 1.813131} ,
{0.978468, -1.813131} ,
{0.978468, -1.818371} ,
{0.978468, 1.818371} ,
{0.978468, 1.823148} ,
{0.978468, -1.823148} ,
{0.978468, 1.827503} ,
{0.978468, -1.827503} ,
{0.978468, 1.831473} ,
{0.978468, -1.831473} ,
{0.978468, 1.835092} ,
{0.978468, -1.835092} ,
{0.978468, -1.838388} ,
{0.978468, 1.838388} ,
{0.978468, -1.841386} ,
{0.978468, 1.841386} ,
{0.978468, 1.844109} ,
{0.978468, -1.844109} ,
{0.978468, 1.846577} ,
{0.978468, -1.846577} ,
{0.978468, -1.848807} ,
{0.978468, 1.848807} ,
{0.978468, 1.850814} ,
{0.978468, -1.850814} ,
{0.978468, 1.852612} ,
{0.978468, -1.852612} ,
{0.978468, 1.854213} ,
{0.978468, -1.854213} ,
{0.978468, 1.855628} ,
{0.978468, -1.855628} ,
{0.978468, 1.856864} ,
{0.978468, -1.856864} ,
{0.978468, -1.857929} ,
{0.978468, 1.857929} ,
{0.978468, 1.858831} ,
{0.978468, -1.858831} ,
{0.978468, 1.859575} ,
{0.978468, -1.859575} ,
{0.978468, -1.860165} ,
{0.978468, 1.860165} ,
{0.978468, 1.860604} ,
{0.978468, -1.860604} ,
{0.978468, 1.860895} ,
{0.978468, -1.860895} ,
{0.978468, 1.861040} ,
{0.978468, -1.861040} 
};

float A3[Korder][2] = { 
{0.037902, 0.927862} ,
{-0.037902, 0.927862} ,
{0.113517, 0.928133} ,
{-0.113517, 0.928133} ,
{-0.188564, 0.928669} ,
{0.188564, 0.928669} ,
{0.262682, 0.929460} ,
{-0.262682, 0.929460} ,
{0.335528, 0.930490} ,
{-0.335528, 0.930490} ,
{0.406794, 0.931740} ,
{-0.406794, 0.931740} ,
{0.476200, 0.933187} ,
{-0.476200, 0.933187} ,
{0.543510, 0.934808} ,
{-0.543510, 0.934808} ,
{-0.608526, 0.936575} ,
{0.608526, 0.936575} ,
{-0.671092, 0.938465} ,
{0.671092, 0.938465} ,
{0.731094, 0.940450} ,
{-0.731094, 0.940450} ,
{0.788453, 0.942506} ,
{-0.788453, 0.942506} ,
{0.843128, 0.944613} ,
{-0.843128, 0.944613} ,
{-0.895109, 0.946747} ,
{0.895109, 0.946747} ,
{-0.944412, 0.948892} ,
{0.944412, 0.948892} ,
{0.991078, 0.951031} ,
{-0.991078, 0.951031} ,
{1.035166, 0.953151} ,
{-1.035166, 0.953151} ,
{1.076751, 0.955239} ,
{-1.076751, 0.955239} ,
{-1.115918, 0.957288} ,
{1.115918, 0.957288} ,
{1.152762, 0.959289} ,
{-1.152762, 0.959289} ,
{-1.187384, 0.961236} ,
{1.187384, 0.961236} ,
{-1.219888, 0.963127} ,
{1.219888, 0.963127} ,
{-1.250377, 0.964957} ,
{1.250377, 0.964957} ,
{-1.278958, 0.966725} ,
{1.278958, 0.966725} ,
{1.305732, 0.968430} ,
{-1.305732, 0.968430} ,
{-1.330800, 0.970073} ,
{1.330800, 0.970073} ,
{1.354258, 0.971655} ,
{-1.354258, 0.971655} ,
{1.376200, 0.973175} ,
{-1.376200, 0.973175} ,
{-1.396715, 0.974637} ,
{1.396715, 0.974637} ,
{-1.415885, 0.976041} ,
{1.415885, 0.976041} ,
{1.433791, 0.977391} ,
{-1.433791, 0.977391} ,
{-1.450506, 0.978689} ,
{1.450506, 0.978689} ,
{1.466100, 0.979936} ,
{-1.466100, 0.979936} ,
{1.480640, 0.981136} ,
{-1.480640, 0.981136} ,
{1.494184, 0.982291} ,
{-1.494184, 0.982291} ,
{-1.506790, 0.983404} ,
{1.506790, 0.983404} ,
{1.518511, 0.984477} ,
{-1.518511, 0.984477} ,
{1.529393, 0.985513} ,
{-1.529393, 0.985513} ,
{1.539482, 0.986514} ,
{-1.539482, 0.986514} ,
{-1.548820, 0.987483} ,
{1.548820, 0.987483} ,
{-1.557443, 0.988423} ,
{1.557443, 0.988423} ,
{1.565385, 0.989334} ,
{-1.565385, 0.989334} ,
{-1.572680, 0.990221} ,
{1.572680, 0.990221} ,
{1.579354, 0.991084} ,
{-1.579354, 0.991084} ,
{-1.585435, 0.991927} ,
{1.585435, 0.991927} ,
{1.590944, 0.992750} ,
{-1.590944, 0.992750} ,
{-1.595904, 0.993557} ,
{1.595904, 0.993557} ,
{-1.600333, 0.994349} ,
{1.600333, 0.994349} ,
{1.604247, 0.995127} ,
{-1.604247, 0.995127} ,
{-1.607660, 0.995895} ,
{1.607660, 0.995895} ,
{1.610584, 0.996653} ,
{-1.610584, 0.996653} ,
{-1.613031, 0.997404} ,
{1.613031, 0.997404} ,
{1.615008, 0.998150} ,
{-1.615008, 0.998150} ,
{-1.616521, 0.998891} ,
{1.616521, 0.998891} ,
{-1.617575, 0.999631} ,
{1.617575, 0.999631} 
};

float B3[Korder][2] = { 
{0.983809, 0.038643} ,
{0.983809, -0.038643} ,
{0.983809, 0.115718} ,
{0.983809, -0.115718} ,
{0.983809, -0.192170} ,
{0.983809, 0.192170} ,
{0.983809, 0.267600} ,
{0.983809, -0.267600} ,
{0.983809, 0.341637} ,
{0.983809, -0.341637} ,
{0.983809, 0.413944} ,
{0.983809, -0.413944} ,
{0.983809, 0.484223} ,
{0.983809, -0.484223} ,
{0.983809, 0.552224} ,
{0.983809, -0.552224} ,
{0.983809, -0.617742} ,
{0.983809, 0.617742} ,
{0.983809, -0.680620} ,
{0.983809, 0.680620} ,
{0.983809, 0.740745} ,
{0.983809, -0.740745} ,
{0.983809, 0.798049} ,
{0.983809, -0.798049} ,
{0.983809, 0.852500} ,
{0.983809, -0.852500} ,
{0.983809, -0.904103} ,
{0.983809, 0.904103} ,
{0.983809, -0.952889} ,
{0.983809, 0.952889} ,
{0.983809, 0.998915} ,
{0.983809, -0.998915} ,
{0.983809, 1.042256} ,
{0.983809, -1.042256} ,
{0.983809, 1.083004} ,
{0.983809, -1.083004} ,
{0.983809, -1.121260} ,
{0.983809, 1.121260} ,
{0.983809, 1.157133} ,
{0.983809, -1.157133} ,
{0.983809, -1.190736} ,
{0.983809, 1.190736} ,
{0.983809, -1.222185} ,
{0.983809, 1.222185} ,
{0.983809, -1.251596} ,
{0.983809, 1.251596} ,
{0.983809, -1.279082} ,
{0.983809, 1.279082} ,
{0.983809, 1.304754} ,
{0.983809, -1.304754} ,
{0.983809, -1.328720} ,
{0.983809, 1.328720} ,
{0.983809, 1.351082} ,
{0.983809, -1.351082} ,
{0.983809, 1.371937} ,
{0.983809, -1.371937} ,
{0.983809, -1.391378} ,
{0.983809, 1.391378} ,
{0.983809, -1.409492} ,
{0.983809, 1.409492} ,
{0.983809, 1.426360} ,
{0.983809, -1.426360} ,
{0.983809, -1.442060} ,
{0.983809, 1.442060} ,
{0.983809, 1.456661} ,
{0.983809, -1.456661} ,
{0.983809, 1.470230} ,
{0.983809, -1.470230} ,
{0.983809, 1.482828} ,
{0.983809, -1.482828} ,
{0.983809, -1.494512} ,
{0.983809, 1.494512} ,
{0.983809, 1.505333} ,
{0.983809, -1.505333} ,
{0.983809, 1.515341} ,
{0.983809, -1.515341} ,
{0.983809, 1.524578} ,
{0.983809, -1.524578} ,
{0.983809, -1.533086} ,
{0.983809, 1.533086} ,
{0.983809, -1.540901} ,
{0.983809, 1.540901} ,
{0.983809, 1.548057} ,
{0.983809, -1.548057} ,
{0.983809, -1.554584} ,
{0.983809, 1.554584} ,
{0.983809, 1.560511} ,
{0.983809, -1.560511} ,
{0.983809, -1.565861} ,
{0.983809, 1.565861} ,
{0.983809, 1.570659} ,
{0.983809, -1.570659} ,
{0.983809, -1.574922} ,
{0.983809, 1.574922} ,
{0.983809, -1.578669} ,
{0.983809, 1.578669} ,
{0.983809, 1.581915} ,
{0.983809, -1.581915} ,
{0.983809, -1.584674} ,
{0.983809, 1.584674} ,
{0.983809, 1.586956} ,
{0.983809, -1.586956} ,
{0.983809, -1.588771} ,
{0.983809, 1.588771} ,
{0.983809, 1.590126} ,
{0.983809, -1.590126} ,
{0.983809, -1.591026} ,
{0.983809, 1.591026} ,
{0.983809, -1.591475} ,
{0.983809, 1.591475} 
};

float A4[Korder][2] = { 
{0.009197, 0.982482} ,
{-0.009197, 0.982482} ,
{0.027580, 0.982499} ,
{-0.027580, 0.982499} ,
{-0.045935, 0.982533} ,
{0.045935, 0.982533} ,
{0.064242, 0.982584} ,
{-0.064242, 0.982584} ,
{-0.082481, 0.982653} ,
{0.082481, 0.982653} ,
{0.100635, 0.982738} ,
{-0.100635, 0.982738} ,
{0.118684, 0.982839} ,
{-0.118684, 0.982839} ,
{-0.136611, 0.982957} ,
{0.136611, 0.982957} ,
{0.154396, 0.983091} ,
{-0.154396, 0.983091} ,
{-0.172023, 0.983241} ,
{0.172023, 0.983241} ,
{-0.189474, 0.983406} ,
{0.189474, 0.983406} ,
{0.206733, 0.983587} ,
{-0.206733, 0.983587} ,
{0.223783, 0.983783} ,
{-0.223783, 0.983783} ,
{-0.240608, 0.983992} ,
{0.240608, 0.983992} ,
{-0.257193, 0.984216} ,
{0.257193, 0.984216} ,
{0.273524, 0.984454} ,
{-0.273524, 0.984454} ,
{-0.289587, 0.984704} ,
{0.289587, 0.984704} ,
{-0.305367, 0.984968} ,
{0.305367, 0.984968} ,
{0.320852, 0.985243} ,
{-0.320852, 0.985243} ,
{0.336031, 0.985531} ,
{-0.336031, 0.985531} ,
{0.350890, 0.985830} ,
{-0.350890, 0.985830} ,
{-0.365419, 0.986139} ,
{0.365419, 0.986139} ,
{0.379608, 0.986459} ,
{-0.379608, 0.986459} ,
{-0.393447, 0.986789} ,
{0.393447, 0.986789} ,
{0.406926, 0.987128} ,
{-0.406926, 0.987128} ,
{0.420038, 0.987477} ,
{-0.420038, 0.987477} ,
{-0.432773, 0.987833} ,
{0.432773, 0.987833} ,
{0.445125, 0.988198} ,
{-0.445125, 0.988198} ,
{0.457086, 0.988571} ,
{-0.457086, 0.988571} ,
{0.468650, 0.988950} ,
{-0.468650, 0.988950} ,
{0.479812, 0.989336} ,
{-0.479812, 0.989336} ,
{0.490565, 0.989729} ,
{-0.490565, 0.989729} ,
{0.500904, 0.990128} ,
{-0.500904, 0.990128} ,
{-0.510826, 0.990532} ,
{0.510826, 0.990532} ,
{0.520325, 0.990941} ,
{-0.520325, 0.990941} ,
{0.529399, 0.991355} ,
{-0.529399, 0.991355} ,
{0.538043, 0.991774} ,
{-0.538043, 0.991774} ,
{0.546254, 0.992197} ,
{-0.546254, 0.992197} ,
{0.554031, 0.992623} ,
{-0.554031, 0.992623} ,
{-0.561369, 0.993053} ,
{0.561369, 0.993053} ,
{0.568267, 0.993487} ,
{-0.568267, 0.993487} ,
{0.574723, 0.993924} ,
{-0.574723, 0.993924} ,
{0.580735, 0.994363} ,
{-0.580735, 0.994363} ,
{0.586302, 0.994805} ,
{-0.586302, 0.994805} ,
{0.591421, 0.995249} ,
{-0.591421, 0.995249} ,
{0.596093, 0.995695} ,
{-0.596093, 0.995695} ,
{-0.600314, 0.996143} ,
{0.600314, 0.996143} ,
{0.604085, 0.996593} ,
{-0.604085, 0.996593} ,
{0.607405, 0.997044} ,
{-0.607405, 0.997044} ,
{0.610272, 0.997496} ,
{-0.610272, 0.997496} ,
{0.612687, 0.997950} ,
{-0.612687, 0.997950} ,
{0.614648, 0.998404} ,
{-0.614648, 0.998404} ,
{0.616154, 0.998860} ,
{-0.616154, 0.998860} ,
{0.617206, 0.999315} ,
{-0.617206, 0.999315} ,
{0.617803, 0.999772} ,
{-0.617803, 0.999772} 
};

float B4[Korder][2] = { 
{0.994575, 0.009224} ,
{0.994575, -0.009224} ,
{0.994575, 0.027662} ,
{0.994575, -0.027662} ,
{0.994575, -0.046070} ,
{0.994575, 0.046070} ,
{0.994575, 0.064428} ,
{0.994575, -0.064428} ,
{0.994575, -0.082718} ,
{0.994575, 0.082718} ,
{0.994575, 0.100919} ,
{0.994575, -0.100919} ,
{0.994575, 0.119014} ,
{0.994575, -0.119014} ,
{0.994575, -0.136982} ,
{0.994575, 0.136982} ,
{0.994575, 0.154805} ,
{0.994575, -0.154805} ,
{0.994575, -0.172466} ,
{0.994575, 0.172466} ,
{0.994575, -0.189946} ,
{0.994575, 0.189946} ,
{0.994575, 0.207229} ,
{0.994575, -0.207229} ,
{0.994575, 0.224298} ,
{0.994575, -0.224298} ,
{0.994575, -0.241137} ,
{0.994575, 0.241137} ,
{0.994575, -0.257731} ,
{0.994575, 0.257731} ,
{0.994575, 0.274063} ,
{0.994575, -0.274063} ,
{0.994575, -0.290121} ,
{0.994575, 0.290121} ,
{0.994575, -0.305891} ,
{0.994575, 0.305891} ,
{0.994575, 0.321359} ,
{0.994575, -0.321359} ,
{0.994575, 0.336513} ,
{0.994575, -0.336513} ,
{0.994575, 0.351341} ,
{0.994575, -0.351341} ,
{0.994575, -0.365833} ,
{0.994575, 0.365833} ,
{0.994575, 0.379978} ,
{0.994575, -0.379978} ,
{0.994575, -0.393766} ,
{0.994575, 0.393766} ,
{0.994575, 0.407187} ,
{0.994575, -0.407187} ,
{0.994575, 0.420234} ,
{0.994575, -0.420234} ,
{0.994575, -0.432899} ,
{0.994575, 0.432899} ,
{0.994575, 0.445173} ,
{0.994575, -0.445173} ,
{0.994575, 0.457051} ,
{0.994575, -0.457051} ,
{0.994575, 0.468526} ,
{0.994575, -0.468526} ,
{0.994575, 0.479592} ,
{0.994575, -0.479592} ,
{0.994575, 0.490245} ,
{0.994575, -0.490245} ,
{0.994575, 0.500478} ,
{0.994575, -0.500478} ,
{0.994575, -0.510289} ,
{0.994575, 0.510289} ,
{0.994575, 0.519672} ,
{0.994575, -0.519672} ,
{0.994575, 0.528625} ,
{0.994575, -0.528625} ,
{0.994575, 0.537145} ,
{0.994575, -0.537145} ,
{0.994575, 0.545228} ,
{0.994575, -0.545228} ,
{0.994575, 0.552872} ,
{0.994575, -0.552872} ,
{0.994575, -0.560075} ,
{0.994575, 0.560075} ,
{0.994575, 0.566835} ,
{0.994575, -0.566835} ,
{0.994575, 0.573150} ,
{0.994575, -0.573150} ,
{0.994575, 0.579019} ,
{0.994575, -0.579019} ,
{0.994575, 0.584440} ,
{0.994575, -0.584440} ,
{0.994575, 0.589413} ,
{0.994575, -0.589413} ,
{0.994575, 0.593936} ,
{0.994575, -0.593936} ,
{0.994575, -0.598008} ,
{0.994575, 0.598008} ,
{0.994575, 0.601630} ,
{0.994575, -0.601630} ,
{0.994575, 0.604800} ,
{0.994575, -0.604800} ,
{0.994575, 0.607518} ,
{0.994575, -0.607518} ,
{0.994575, 0.609783} ,
{0.994575, -0.609783} ,
{0.994575, 0.611596} ,
{0.994575, -0.611596} ,
{0.994575, 0.612956} ,
{0.994575, -0.612956} ,
{0.994575, 0.613862} ,
{0.994575, -0.613862} ,
{0.994575, 0.614316} ,
{0.994575, -0.614316} 
};

float A1[Korder][2] = { 
{0.181602, 0.666248} ,
{-0.181602, 0.666248} ,
{-0.524900, 0.696650} ,
{0.524900, 0.696650} ,
{-0.818299, 0.744410} ,
{0.818299, 0.744410} ,
{-1.051341, 0.795450} ,
{1.051341, 0.795450} ,
{-1.228272, 0.841861} ,
{1.228272, 0.841861} ,
{-1.359317, 0.881270} ,
{1.359317, 0.881270} ,
{-1.455005, 0.914141} ,
{1.455005, 0.914141} ,
{-1.523916, 0.941946} ,
{1.523916, 0.941946} ,
{1.572288, 0.966339} ,
{-1.572288, 0.966339} ,
{1.604271, 0.988914} ,
{-1.604271, 0.988914} 
};

float B1[Korder][2] = { 
{0.914614, 0.193179} ,
{0.914614, -0.193179} ,
{0.914614, -0.551152} ,
{0.914614, 0.551152} ,
{0.914614, -0.841353} ,
{0.914614, 0.841353} ,
{0.914614, -1.056243} ,
{0.914614, 1.056243} ,
{0.914614, -1.207727} ,
{0.914614, 1.207727} ,
{0.914614, -1.311981} ,
{0.914614, 1.311981} ,
{0.914614, -1.382467} ,
{0.914614, 1.382467} ,
{0.914614, -1.428630} ,
{0.914614, 1.428630} ,
{0.914614, 1.456521} ,
{0.914614, -1.456521} ,
{0.914614, 1.469661} ,
{0.914614, -1.469661} 
};

float A1[Korder][2] = { 
{0.181602, 0.666248} ,
{-0.181602, 0.666248} ,
{-0.524900, 0.696650} ,
{0.524900, 0.696650} ,
{-0.818299, 0.744410} ,
{0.818299, 0.744410} ,
{-1.051341, 0.795450} ,
{1.051341, 0.795450} ,
{-1.228272, 0.841861} ,
{1.228272, 0.841861} ,
{-1.359317, 0.881270} ,
{1.359317, 0.881270} ,
{-1.455005, 0.914141} ,
{1.455005, 0.914141} ,
{-1.523916, 0.941946} ,
{1.523916, 0.941946} ,
{1.572288, 0.966339} ,
{-1.572288, 0.966339} ,
{1.604271, 0.988914} ,
{-1.604271, 0.988914} 
};

float B1[Korder][2] = { 
{0.914614, 0.193179} ,
{0.914614, -0.193179} ,
{0.914614, -0.551152} ,
{0.914614, 0.551152} ,
{0.914614, -0.841353} ,
{0.914614, 0.841353} ,
{0.914614, -1.056243} ,
{0.914614, 1.056243} ,
{0.914614, -1.207727} ,
{0.914614, 1.207727} ,
{0.914614, -1.311981} ,
{0.914614, 1.311981} ,
{0.914614, -1.382467} ,
{0.914614, 1.382467} ,
{0.914614, -1.428630} ,
{0.914614, 1.428630} ,
{0.914614, 1.456521} ,
{0.914614, -1.456521} ,
{0.914614, 1.469661} ,
{0.914614, -1.469661} 
};

