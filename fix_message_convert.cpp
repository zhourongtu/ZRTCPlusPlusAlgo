#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    string my_str = "8=FIXT.1.1|9=71|35=2|34=2657|49=FTSEC|52=20200706-13:23:30.941|56=FTINC_DC|7=3235|16=0|10=168|";
    map<int ,string> map_for_fix_code = {{1,"Account"}, {2,"AdvId"}, {3,"AdvRefID"},{4,"AdvSide"},{5,"AdvTransType"},{6,"AvgPx"},{7,"BeginSeqNo"},{8,"BeginString"},{9,"BodyLength"},{10,"CheckSum"},{11,"ClOrdID"},{12,"Commission"},{13,"CommType"},{14,"CumQty"},{15,"Currency"},{16,"EndSeqNo"},{17,"ExecID"},{18,"ExecInst"},{19,"ExecRefID"},{20,"ExecTransType"},{21,"HandlInst"},{22,"SecurityIDSource"},{23,"IOIID"},{25,"IOIQltyInd"},{26,"IOIRefID"},{27,"IOIQty"},{28,"IOITransType"},{29,"LastCapacity"},{30,"LastMkt"},{31,"LastPx"},{32,"LastQty"},{33,"NoLinesOfText"},{34,"MsgSeqNum"},{35,"MsgType"},{36,"NewSeqNo"},{37,"OrderID"},{38,"OrderQty"},{39,"OrdStatus"},{40,"OrdType"},{41,"OrigClOrdID"},{42,"OrigTime"},{43,"PossDupFlag"},{44,"Price"},{45,"RefSeqNum"},{46,"RelatdSym"},{47,"Rule80A(aka OrderCapacity)"},{48,"SecurityID"},{49,"SenderCompID"},{50,"SenderSubID"},{52,"SendingTime"},{53,"Quantity"},{54,"Side"},{55,"Symbol"},{56,"TargetCompID"},{57,"TargetSubID"},{58,"Text"},{59,"TimeInForce"},{60,"TransactTime"},{61,"Urgency"},{62,"ValidUntilTime"},{63,"SettlType"},{64,"SettlDate"},{65,"SymbolSfx"},{66,"ListID"},{67,"ListSeqNo"},{68,"TotNoOrders"},{69,"ListExecInst"},{70,"AllocID"},{71,"AllocTransType"},{72,"RefAllocID"},{73,"NoOrders"},{74,"AvgPxPrecision"},{75,"TradeDate"},{76,"ExecBroker"},{77,"PositionEffect"},{78,"NoAllocs"},{79,"AllocAccount"},{80,"AllocQty"},{81,"ProcessCode"},{82,"NoRpts"},{83,"RptSeq"},{84,"CxlQty"},{85,"NoDlvyInst"},{86,"DlvyInst"},{87,"AllocStatus"},{88,"AllocRejCode"},{89,"Signature"},{90,"SecureDataLen"},{91,"SecureData"},{92,"BrokerOfCredit"},{93,"SignatureLength"},{94,"EmailType"},{95,"RawDataLength"},{96,"RawData"},{97,"PossResend"},{98,"EncryptMethod"},{99,"StopPx"},{100,"ExDestination"},{102,"CxlRejReason"},{103,"OrdRejReason"},{104,"IOIQualifier"},{105,"WaveNo"},{106,"Issuer"},{107,"SecurityDesc"},{108,"HeartBtInt"},{109,"ClientID"},{110,"MinQty"},{111,"MaxFloor"},{112,"TestReqID"},{113,"ReportToExch"},{114,"LocateReqd"},{115,"OnBehalfOfCompID"},{116,"OnBehalfOfSubID"},{117,"QuoteID"},{118,"NetMoney"},{119,"SettlCurrAmt"},{120,"SettlCurrency"},{121,"ForexReq"},{122,"OrigSendingTime"},{123,"GapFillFlag"},{124,"NoExecs"},{126,"ExpireTime"},{127,"DKReason"},{128,"DeliverToCompID"},{129,"DeliverToSubID"},{130,"IOINaturalFlag"},{131,"QuoteReqID"},{132,"BidPx"},{133,"OfferPx"},{134,"BidSize"},{135,"OfferSize"},{136,"NoMiscFees"},{137,"MiscFeeAmt"},{138,"MiscFeeCurr"},{139,"MiscFeeType"},{140,"PrevClosePx"},{141,"ResetSeqNumFlag"},{142,"SenderLocationID"},{143,"TargetLocationID"},{144,"OnBehalfOfLocationID"},{145,"DeliverToLocationID"},{146,"NoRelatedSym"},{147,"Subject"},{148,"Headline"},{149,"URLLink"},{150,"ExecType"},{151,"LeavesQty"},{152,"CashOrderQty"},{153,"AllocAvgPx"},{154,"AllocNetMoney"},{155,"SettlCurrFxRate"},{156,"SettlCurrFxRateCalc"},{157,"NumDaysInterest"},{158,"AccruedInterestRate"},{159,"AccruedInterestAmt"},{160,"SettlInstMode"},{161,"AllocText"},{162,"SettlInstID"},{163,"SettlInstTransType"},{164,"EmailThreadID"},{165,"SettlInstSource"},{167,"SecurityType"},{168,"EffectiveTime"},{169,"StandInstDbType"},{170,"StandInstDbName"},{171,"StandInstDbID"},{172,"SettlDeliveryType"},{173,"SettlDepositoryCode"},{174,"SettlBrkrCode"},{175,"SettlInstCode"},{176,"SecuritySettlAgentName"},{177,"SecuritySettlAgentCode"},{178,"SecuritySettlAgentAcctNum"},{179,"SecuritySettlAgentAcctName"},{180,"SecuritySettlAgentContactName"},{181,"SecuritySettlAgentContactPhone"},{182,"CashSettlAgentName"},{183,"CashSettlAgentCode"},{184,"CashSettlAgentAcctNum"},{185,"CashSettlAgentAcctName"},{186,"CashSettlAgentContactName"},{187,"CashSettlAgentContactPhone"},{188,"BidSpotRate"},{189,"BidForwardPoints"},{190,"OfferSpotRate"},{191,"OfferForwardPoints"},{192,"OrderQty2"},{193,"SettlDate2"},{194,"LastSpotRate"},{195,"LastForwardPoints"},{196,"AllocLinkID"},{197,"AllocLinkType"},{198,"SecondaryOrderID"},{199,"NoIOIQualifiers"},{200,"MaturityMonthYear"},{201,"PutOrCall"},{202,"StrikePrice"},{203,"CoveredOrUncovered"},{206,"OptAttribute"},{207,"SecurityExchange"},{208,"NotifyBrokerOfCredit"},{209,"AllocHandlInst"},{210,"MaxShow"},{211,"PegOffsetValue"},{212,"XmlDataLen"},{213,"XmlData"},{214,"SettlInstRefID"},{215,"NoRoutingIDs"},{216,"RoutingType"},{217,"RoutingID"},{218,"Spread"},{220,"BenchmarkCurveCurrency"},{221,"BenchmarkCurveName"},{222,"BenchmarkCurvePoint"},{223,"CouponRate"},{224,"CouponPaymentDate"},{225,"IssueDate"},{226,"RepurchaseTerm"},{227,"RepurchaseRate"},{228,"Factor"},{229,"TradeOriginationDate"},{230,"ExDate"},{231,"ContractMultiplier"},{232,"NoStipulations"},{233,"StipulationType"},{234,"StipulationValue"},{235,"YieldType"},{236,"Yield"},{237,"TotalTakedown"},{238,"Concession"},{239,"RepoCollateralSecurityType"},{240,"RedemptionDate"},{241,"UnderlyingCouponPaymentDate"},{242,"UnderlyingIssueDate"},{243,"UnderlyingRepoCollateralSecurityType"},{244,"UnderlyingRepurchaseTerm"},{245,"UnderlyingRepurchaseRate"},{246,"UnderlyingFactor"},{247,"UnderlyingRedemptionDate"},{248,"LegCouponPaymentDate"},{249,"LegIssueDate"},{250,"LegRepoCollateralSecurityType"},{251,"LegRepurchaseTerm"},{252,"LegRepurchaseRate"},{253,"LegFactor"},{254,"LegRedemptionDate"},{255,"CreditRating"},{256,"UnderlyingCreditRating"},{257,"LegCreditRating"},{258,"TradedFlatSwitch"},{259,"BasisFeatureDate"},{260,"BasisFeaturePrice"},{262,"MDReqID"},{263,"SubscriptionRequestType"},{264,"MarketDepth"},{265,"MDUpdateType"},{266,"AggregatedBook"},{267,"NoMDEntryTypes"},{268,"NoMDEntries"},{269,"MDEntryType"},{270,"MDEntryPx"},{271,"MDEntrySize"},{272,"MDEntryDate"},{273,"MDEntryTime"},{274,"TickDirection"},{275,"MDMkt"},{276,"QuoteCondition"},{277,"TradeCondition"},{278,"MDEntryID"},{279,"MDUpdateAction"},{280,"MDEntryRefID"},{281,"MDReqRejReason"},{282,"MDEntryOriginator"},{283,"LocationID"},{284,"DeskID"},{285,"DeleteReason"},{286,"OpenCloseSettlFlag"},{287,"SellerDays"},{288,"MDEntryBuyer"},{289,"MDEntrySeller"},{290,"MDEntryPositionNo"},{291,"FinancialStatus"},{292,"CorporateAction"},{293,"DefBidSize"},{294,"DefOfferSize"},{295,"NoQuoteEntries"},{296,"NoQuoteSets"},{297,"QuoteStatus"},{298,"QuoteCancelType"},{299,"QuoteEntryID"},{300,"QuoteRejectReason"},{301,"QuoteResponseLevel"},{302,"QuoteSetID"},{303,"QuoteRequestType"},{304,"TotNoQuoteEntries"},{305,"UnderlyingSecurityIDSource"},{306,"UnderlyingIssuer"},{307,"UnderlyingSecurityDesc"},{308,"UnderlyingSecurityExchange"},{309,"UnderlyingSecurityID"},{310,"UnderlyingSecurityType"},{311,"UnderlyingSymbol"},{312,"UnderlyingSymbolSfx"},{313,"UnderlyingMaturityMonthYear"},{315,"UnderlyingPutOrCall"},{316,"UnderlyingStrikePrice"},{317,"UnderlyingOptAttribute"},{318,"UnderlyingCurrency"},{320,"SecurityReqID"},{321,"SecurityRequestType"},{322,"SecurityResponseID"},{323,"SecurityResponseType"},{324,"SecurityStatusReqID"},{325,"UnsolicitedIndicator"},{326,"SecurityTradingStatus"},{327,"HaltReasonInt"},{328,"InViewOfCommon"},{329,"DueToRelated"},{330,"BuyVolume"},{331,"SellVolume"},{332,"HighPx"},{333,"LowPx"},{334,"Adjustment"},{335,"TradSesReqID"},{336,"TradingSessionID"},{337,"ContraTrader"},{338,"TradSesMethod"},{339,"TradSesMode"},{340,"TradSesStatus"},{341,"TradSesStartTime"},{342,"TradSesOpenTime"},{343,"TradSesPreCloseTime"},{344,"TradSesCloseTime"},{345,"TradSesEndTime"},{346,"NumberOfOrders"},{347,"MessageEncoding"},{348,"EncodedIssuerLen"},{349,"EncodedIssuer"},{350,"EncodedSecurityDescLen"},{351,"EncodedSecurityDesc"},{352,"EncodedListExecInstLen"},{353,"EncodedListExecInst"},{354,"EncodedTextLen"},{355,"EncodedText"},{356,"EncodedSubjectLen"},{357,"EncodedSubject"},{358,"EncodedHeadlineLen"},{359,"EncodedHeadline"},{360,"EncodedAllocTextLen"},{361,"EncodedAllocText"},{362,"EncodedUnderlyingIssuerLen"},{363,"EncodedUnderlyingIssuer"},{364,"EncodedUnderlyingSecurityDescLen"},{365,"EncodedUnderlyingSecurityDesc"},{366,"AllocPrice"},{367,"QuoteSetValidUntilTime"},{368,"QuoteEntryRejectReason"},{369,"LastMsgSeqNumProcessed"},{371,"RefTagID"},{372,"RefMsgType"},{373,"SessionRejectReason"},{374,"BidRequestTransType"},{375,"ContraBroker"},{376,"ComplianceID"},{377,"SolicitedFlag"},{378,"ExecRestatementReason"},{379,"BusinessRejectRefID"},{380,"BusinessRejectReason"},{381,"GrossTradeAmt"},{382,"NoContraBrokers"},{383,"MaxMessageSize"},{384,"NoMsgTypes"},{385,"MsgDirection"},{386,"NoTradingSessions"},{387,"TotalVolumeTraded"},{388,"DiscretionInst"},{389,"DiscretionOffsetValue"},{390,"BidID"},{391,"ClientBidID"},{392,"ListName"},{393,"TotNoRelatedSym"},{394,"BidType"},{395,"NumTickets"},{396,"SideValue1"},{397,"SideValue2"},{398,"NoBidDescriptors"},{399,"BidDescriptorType"},{400,"BidDescriptor"},{401,"SideValueInd"},{402,"LiquidityPctLow"},{403,"LiquidityPctHigh"},{404,"LiquidityValue"},{405,"EFPTrackingError"},{406,"FairValue"},{407,"OutsideIndexPct"},{408,"ValueOfFutures"},{409,"LiquidityIndType"},{410,"WtAverageLiquidity"},{411,"ExchangeForPhysical"},{412,"OutMainCntryUIndex"},{413,"CrossPercent"},{414,"ProgRptReqs"},{415,"ProgPeriodInterval"},{416,"IncTaxInd"},{417,"NumBidders"},{418,"BidTradeType"},{419,"BasisPxType"},{420,"NoBidComponents"},{421,"Country"},{422,"TotNoStrikes"},{423,"PriceType"},{424,"DayOrderQty"},{425,"DayCumQty"},{426,"DayAvgPx"},{427,"GTBookingInst"},{428,"NoStrikes"},{429,"ListStatusType"},{430,"NetGrossInd"},{431,"ListOrderStatus"},{432,"ExpireDate"},{433,"ListExecInstType"},{434,"CxlRejResponseTo"},{435,"UnderlyingCouponRate"},{436,"UnderlyingContractMultiplier"},{437,"ContraTradeQty"},{438,"ContraTradeTime"},{441,"LiquidityNumSecurities"},{442,"MultiLegReportingType"},{443,"StrikeTime"},{444,"ListStatusText"},{445,"EncodedListStatusTextLen"},{446,"EncodedListStatusText"},{447,"PartyIDSource"},{448,"PartyID"},{451,"NetChgPrevDay"},{452,"PartyRole"},{453,"NoPartyIDs"},{454,"NoSecurityAltID"},{455,"SecurityAltID"},{456,"SecurityAltIDSource"},{457,"NoUnderlyingSecurityAltID"},{458,"UnderlyingSecurityAltID"},{459,"UnderlyingSecurityAltIDSource"},{460,"Product"},{461,"CFICode"},{462,"UnderlyingProduct"},{463,"UnderlyingCFICode"},{464,"TestMessageIndicator"},
    {466,"BookingRefID"},{467,"IndividualAllocID"},{468,"RoundingDirection"},{469,"RoundingModulus"},{470,"CountryOfIssue"},{471,"StateOrProvinceOfIssue"},{472,"LocaleOfIssue"},{473,"NoRegistDtls"},{474,"MailingDtls"},{475,"InvestorCountryOfResidence"},{476,"PaymentRef"},{477,"DistribPaymentMethod"},{478,"CashDistribCurr"},{479,"CommCurrency"},{480,"CancellationRights"},{481,"MoneyLaunderingStatus"},{482,"MailingInst"},{483,"TransBkdTime"},{484,"ExecPriceType"},{485,"ExecPriceAdjustment"},{486,"DateOfBirth"},{487,"TradeReportTransType"},{488,"CardHolderName"},{489,"CardNumber"},{490,"CardExpDate"},{491,"CardIssNum"},{492,"PaymentMethod"},{493,"RegistAcctType"},{494,"Designation"},{495,"TaxAdvantageType"},{496,"RegistRejReasonText"},{497,"FundRenewWaiv"},{498,"CashDistribAgentName"},{499,"CashDistribAgentCode"},{500,"CashDistribAgentAcctNumber"},{501,"CashDistribPayRef"},{502,"CashDistribAgentAcctName"},{503,"CardStartDate"},{504,"PaymentDate"},{505,"PaymentRemitterID"},{506,"RegistStatus"},{507,"RegistRejReasonCode"},{508,"RegistRefID"},{509,"RegistDtls"},{510,"NoDistribInsts"},{511,"RegistEmail"},{512,"DistribPercentage"},{513,"RegistID"},{514,"RegistTransType"},{515,"ExecValuationPoint"},{516,"OrderPercent"},{517,"OwnershipType"},{518,"NoContAmts"},{519,"ContAmtType"},{520,"ContAmtValue"},{521,"ContAmtCurr"},{522,"OwnerType"},{523,"PartySubID"},{524,"NestedPartyID"},{525,"NestedPartyIDSource"},{526,"SecondaryClOrdID"},{527,"SecondaryExecID"},{528,"OrderCapacity"},{529,"OrderRestrictions"},{530,"MassCancelRequestType"},{531,"MassCancelResponse"},{532,"MassCancelRejectReason"},{533,"TotalAffectedOrders"},{534,"NoAffectedOrders"},{535,"AffectedOrderID"},{536,"AffectedSecondaryOrderID"},{537,"QuoteType"},{538,"NestedPartyRole"},{539,"NoNestedPartyIDs"},{540,"TotalAccruedInterestAmt"},{541,"MaturityDate"},{542,"UnderlyingMaturityDate"},{543,"InstrRegistry"},{544,"CashMargin"},{545,"NestedPartySubID"},{546,"Scope"},{547,"MDImplicitDelete"},{548,"CrossID"},{549,"CrossType"},{550,"CrossPrioritization"},{551,"OrigCrossID"},{552,"NoSides"},{553,"Username"},{554,"Password"},{555,"NoLegs"},{556,"LegCurrency"},{557,"TotNoSecurityTypes"},{558,"NoSecurityTypes"},{559,"SecurityListRequestType"},{560,"SecurityRequestResult"},{561,"RoundLot"},{562,"MinTradeVol"},{563,"MultiLegRptTypeReq"},{564,"LegPositionEffect"},{565,"LegCoveredOrUncovered"},{566,"LegPrice"},{567,"TradSesStatusRejReason"},{568,"TradeRequestID"},{569,"TradeRequestType"},{570,"PreviouslyReported"},{571,"TradeReportID"},{572,"TradeReportRefID"},{573,"MatchStatus"},{574,"MatchType"},{575,"OddLot"},{576,"NoClearingInstructions"},{577,"ClearingInstruction"},{578,"TradeInputSource"},{579,"TradeInputDevice"},{580,"NoDates"},{581,"AccountType"},{582,"CustOrderCapacity"},{583,"ClOrdLinkID"},{584,"MassStatusReqID"},{585,"MassStatusReqType"},{586,"OrigOrdModTime"},{587,"LegSettlType"},{588,"LegSettlDate"},{589,"DayBookingInst"},{590,"BookingUnit"},{591,"PreallocMethod"},{592,"UnderlyingCountryOfIssue"},{593,"UnderlyingStateOrProvinceOfIssue"},{594,"UnderlyingLocaleOfIssue"},{595,"UnderlyingInstrRegistry"},{596,"LegCountryOfIssue"},{597,"LegStateOrProvinceOfIssue"},{598,"LegLocaleOfIssue"},{599,"LegInstrRegistry"},{600,"LegSymbol"},{601,"LegSymbolSfx"},{602,"LegSecurityID"},{603,"LegSecurityIDSource"},{604,"NoLegSecurityAltID"},{605,"LegSecurityAltID"},{606,"LegSecurityAltIDSource"},{607,"LegProduct"},{608,"LegCFICode"},{609,"LegSecurityType"},{610,"LegMaturityMonthYear"},{611,"LegMaturityDate"},{612,"LegStrikePrice"},{613,"LegOptAttribute"},{614,"LegContractMultiplier"},{615,"LegCouponRate"},{616,"LegSecurityExchange"},{617,"LegIssuer"},{618,"EncodedLegIssuerLen"},{619,"EncodedLegIssuer"},{620,"LegSecurityDesc"},{621,"EncodedLegSecurityDescLen"},{622,"EncodedLegSecurityDesc"},{623,"LegRatioQty"},{624,"LegSide"},{625,"TradingSessionSubID"},{626,"AllocType"},{627,"NoHops"},{628,"HopCompID"},{629,"HopSendingTime"},{630,"HopRefID"},{631,"MidPx"},{632,"BidYield"},{633,"MidYield"},{634,"OfferYield"},{635,"ClearingFeeIndicator"},{636,"WorkingIndicator"},{637,"LegLastPx"},{638,"PriorityIndicator"},{639,"PriceImprovement"},{640,"Price2"},{641,"LastForwardPoints2"},{642,"BidForwardPoints2"},{643,"OfferForwardPoints2"},{644,"RFQReqID"},{645,"MktBidPx"},{646,"MktOfferPx"},{647,"MinBidSize"},{648,"MinOfferSize"},{649,"QuoteStatusReqID"},{650,"LegalConfirm"},{651,"UnderlyingLastPx"},{652,"UnderlyingLastQty"},{654,"LegRefID"},{655,"ContraLegRefID"},{656,"SettlCurrBidFxRate"},{657,"SettlCurrOfferFxRate"},{658,"QuoteRequestRejectReason"},{659,"SideComplianceID"},{660,"AcctIDSource"},{661,"AllocAcctIDSource"},{662,"BenchmarkPrice"},{663,"BenchmarkPriceType"},{664,"ConfirmID"},{665,"ConfirmStatus"},{666,"ConfirmTransType"},{667,"ContractSettlMonth"},{668,"DeliveryForm"},{669,"LastParPx"},{670,"NoLegAllocs"},{671,"LegAllocAccount"},{672,"LegIndividualAllocID"},{673,"LegAllocQty"},{674,"LegAllocAcctIDSource"},{675,"LegSettlCurrency"},{676,"LegBenchmarkCurveCurrency"},{677,"LegBenchmarkCurveName"},{678,"LegBenchmarkCurvePoint"},{679,"LegBenchmarkPrice"},{680,"LegBenchmarkPriceType"},{681,"LegBidPx"},{682,"LegIOIQty"},{683,"NoLegStipulations"},{684,"LegOfferPx"},{685,"LegOrderQty"},{686,"LegPriceType"},{687,"LegQty"},{688,"LegStipulationType"},{689,"LegStipulationValue"},{690,"LegSwapType"},{691,"Pool"},{692,"QuotePriceType"},{693,"QuoteRespID"},{694,"QuoteRespType"},{695,"QuoteQualifier"},{696,"YieldRedemptionDate"},{697,"YieldRedemptionPrice"},{698,"YieldRedemptionPriceType"},{699,"BenchmarkSecurityID"},{700,"ReversalIndicator"},{701,"YieldCalcDate"},{702,"NoPositions"},{703,"PosType"},{704,"LongQty"},{705,"ShortQty"},{706,"PosQtyStatus"},{707,"PosAmtType"},{708,"PosAmt"},{709,"PosTransType"},{710,"PosReqID"},{711,"NoUnderlyings"},{712,"PosMaintAction"},{713,"OrigPosReqRefID"},{714,"PosMaintRptRefID"},{715,"ClearingBusinessDate"},{716,"SettlSessID"},{717,"SettlSessSubID"},{718,"AdjustmentType"},{719,"ContraryInstructionIndicator"},{720,"PriorSpreadIndicator"},{721,"PosMaintRptID"},{722,"PosMaintStatus"},{723,"PosMaintResult"},{724,"PosReqType"},{725,"ResponseTransportType"},{726,"ResponseDestination"},{727,"TotalNumPosReports"},{728,"PosReqResult"},{729,"PosReqStatus"},{730,"SettlPrice"},{731,"SettlPriceType"},{732,"UnderlyingSettlPrice"},{733,"UnderlyingSettlPriceType"},{734,"PriorSettlPrice"},{735,"NoQuoteQualifiers"},{736,"AllocSettlCurrency"},{737,"AllocSettlCurrAmt"},{738,"InterestAtMaturity"},{739,"LegDatedDate"},{740,"LegPool"},{741,"AllocInterestAtMaturity"},{742,"AllocAccruedInterestAmt"},{743,"DeliveryDate"},{744,"AssignmentMethod"},{745,"AssignmentUnit"},{746,"OpenInterest"},{747,"ExerciseMethod"},{748,"TotNumTradeReports"},{749,"TradeRequestResult"},{750,"TradeRequestStatus"},{751,"TradeReportRejectReason"},{752,"SideMultiLegReportingType"},{753,"NoPosAmt"},{754,"AutoAcceptIndicator"},{755,"AllocReportID"},{756,"NoNested2PartyIDs"},{757,"Nested2PartyID"},{758,"Nested2PartyIDSource"},{759,"Nested2PartyRole"},{760,"Nested2PartySubID"},{761,"BenchmarkSecurityIDSource"},{762,"SecuritySubType"},{763,"UnderlyingSecuritySubType"},{764,"LegSecuritySubType"},{765,"AllowableOneSidednessPct"},{766,"AllowableOneSidednessValue"},{767,"AllowableOneSidednessCurr"},{768,"NoTrdRegTimestamps"},{769,"TrdRegTimestamp"},{770,"TrdRegTimestampType"},{771,"TrdRegTimestampOrigin"},{772,"ConfirmRefID"},{773,"ConfirmType"},{774,"ConfirmRejReason"},{775,"BookingType"},{776,"IndividualAllocRejCode"},{777,"SettlInstMsgID"},{778,"NoSettlInst"},{779,"LastUpdateTime"},{780,"AllocSettlInstType"},{781,"NoSettlPartyIDs"},{782,"SettlPartyID"},{783,"SettlPartyIDSource"},{784,"SettlPartyRole"},{785,"SettlPartySubID"},{786,"SettlPartySubIDType"},{787,"DlvyInstType"},{788,"TerminationType"},{789,"NextExpectedMsgSeqNum"},{790,"OrdStatusReqID"},{791,"SettlInstReqID"},{792,"SettlInstReqRejCode"},{793,"SecondaryAllocID"},{794,"AllocReportType"},{795,"AllocReportRefID"},{796,"AllocCancReplaceReason"},{797,"CopyMsgIndicator"},{798,"AllocAccountType"},{799,"OrderAvgPx"},{800,"OrderBookingQty"},{801,"NoSettlPartySubIDs"},{802,"NoPartySubIDs"},{803,"PartySubIDType"},{804,"NoNestedPartySubIDs"},{805,"NestedPartySubIDType"},{806,"NoNested2PartySubIDs"},{807,"Nested2PartySubIDType"},{808,"AllocIntermedReqType"},{810,"UnderlyingPx"},{811,"PriceDelta"},{812,"ApplQueueMax"},{813,"ApplQueueDepth"},{814,"ApplQueueResolution"},{815,"ApplQueueAction"},{816,"NoAltMDSource"},{817,"AltMDSourceID"},{818,"SecondaryTradeReportID"},{819,"AvgPxIndicator"},{820,"TradeLinkID"},{821,"OrderInputDevice"},{822,"UnderlyingTradingSessionID"},{823,"UnderlyingTradingSessionSubID"},{824,"TradeLegRefID"},{825,"ExchangeRule"},{826,"TradeAllocIndicator"},{827,"ExpirationCycle"},{828,"TrdType"},{829,"TrdSubType"},{830,"TransferReason"},{832,"TotNumAssignmentReports"},{833,"AsgnRptID"},{834,"ThresholdAmount"},{835,"PegMoveType"},{836,"PegOffsetType"},{837,"PegLimitType"},{838,"PegRoundDirection"},{839,"PeggedPrice"},{840,"PegScope"},{841,"DiscretionMoveType"},{842,"DiscretionOffsetType"},{843,"DiscretionLimitType"},{844,"DiscretionRoundDirection"},{845,"DiscretionPrice"},{846,"DiscretionScope"},{847,"TargetStrategy"},{848,"TargetStrategyParameters"},{849,"ParticipationRate"},{850,"TargetStrategyPerformance"},{851,"LastLiquidityInd"},{852,"PublishTrdIndicator"},{853,"ShortSaleReason"},{854,"QtyType"},{855,"SecondaryTrdType"},{856,"TradeReportType"},{857,"AllocNoOrdersType"},{858,"SharedCommission"},{859,"ConfirmReqID"},{860,"AvgParPx"},{861,"ReportedPx"},{862,"NoCapacities"},{863,"OrderCapacityQty"},{864,"NoEvents"},{865,"EventType"},{866,"EventDate"},{867,"EventPx"},{868,"EventText"},{869,"PctAtRisk"},{870,"NoInstrAttrib"},{871,"InstrAttribType"},{872,"InstrAttribValue"},{873,"DatedDate"},{874,"InterestAccrualDate"},{875,"CPProgram"},{876,"CPRegType"},{877,"UnderlyingCPProgram"},{878,"UnderlyingCPRegType"},{879,"UnderlyingQty"},{880,"TrdMatchID"},{881,"SecondaryTradeReportRefID"},{882,"UnderlyingDirtyPrice"},{883,"UnderlyingEndPrice"},
    {884,"UnderlyingStartValue"},{885,"UnderlyingCurrentValue"},{886,"UnderlyingEndValue"},{887,"NoUnderlyingStips"},{888,"UnderlyingStipType"},{889,"UnderlyingStipValue"},{890,"MaturityNetMoney"},{891,"MiscFeeBasis"},{892,"TotNoAllocs"},{893,"LastFragment"},{894,"CollReqID"},{895,"CollAsgnReason"},{896,"CollInquiryQualifier"},{897,"NoTrades"},{898,"MarginRatio"},{899,"MarginExcess"},{900,"TotalNetValue"},{901,"CashOutstanding"},{902,"CollAsgnID"},{903,"CollAsgnTransType"},{904,"CollRespID"},{905,"CollAsgnRespType"},{906,"CollAsgnRejectReason"},{907,"CollAsgnRefID"},{908,"CollRptID"},{909,"CollInquiryID"},{910,"CollStatus"},{911,"TotNumReports"},{912,"LastRptRequested"},{913,"AgreementDesc"},{914,"AgreementID"},{915,"AgreementDate"},{916,"StartDate"},{917,"EndDate"},{918,"AgreementCurrency"},{919,"DeliveryType"},{920,"EndAccruedInterestAmt"},{921,"StartCash"},{922,"EndCash"},{923,"UserRequestID"},{924,"UserRequestType"},{925,"NewPassword"},{926,"UserStatus"},{927,"UserStatusText"},{928,"StatusValue"},{929,"StatusText"},{930,"RefCompID"},{931,"RefSubID"},{932,"NetworkResponseID"},{933,"NetworkRequestID"},{934,"LastNetworkResponseID"},{935,"NetworkRequestType"},{936,"NoCompIDs"},{937,"NetworkStatusResponseType"},{938,"NoCollInquiryQualifier"},{939,"TrdRptStatus"},{940,"AffirmStatus"},{941,"UnderlyingStrikeCurrency"},{942,"LegStrikeCurrency"},{943,"TimeBracket"},{944,"CollAction"},{945,"CollInquiryStatus"},{946,"CollInquiryResult"},{947,"StrikeCurrency"},{948,"NoNested3PartyIDs"},{949,"Nested3PartyID"},{950,"Nested3PartyIDSource"},{951,"Nested3PartyRole"},{952,"NoNested3PartySubIDs"},{953,"Nested3PartySubID"},{954,"Nested3PartySubIDType"},{955,"LegContractSettlMonth"},{956,"LegInterestAccrualDate"},{957,"NoStrategyParameters"},{958,"StrategyParameterName"},{959,"StrategyParameterType"},{960,"StrategyParameterValue"},{961,"HostCrossID"},{962,"SideTimeInForce"},{963,"MDReportID"},{964,"SecurityReportID"},{965,"SecurityStatus"},{966,"SettleOnOpenFlag"},{967,"StrikeMultiplier"},{968,"StrikeValue"},{969,"MinPriceIncrement"},{970,"PositionLimit"},{971,"NTPositionLimit"},{972,"UnderlyingAllocationPercent"},{973,"UnderlyingCashAmount"},{974,"UnderlyingCashType"},{975,"UnderlyingSettlementType"},{976,"QuantityDate"},{977,"ContIntRptID"},{978,"LateIndicator"},{979,"InputSource"},{980,"SecurityUpdateAction"},{981,"NoExpiration"},{982,"ExpirationQtyType"},{983,"ExpQty"},{984,"NoUnderlyingAmounts"},{985,"UnderlyingPayAmount"},{986,"UnderlyingCollectAmount"},{987,"UnderlyingSettlementDate"},{988,"UnderlyingSettlementStatus"},{989,"SecondaryIndividualAllocID"},{990,"LegReportID"},{991,"RndPx"},{992,"IndividualAllocType"},{993,"AllocCustomerCapacity"},{994,"TierCode"},{996,"UnitOfMeasure"},{997,"TimeUnit"},{998,"UnderlyingUnitOfMeasure"},{999,"LegUnitOfMeasure"},{1000,"UnderlyingTimeUnit"},{1001,"LegTimeUnit"},{1002,"AllocMethod"},{1003,"TradeID"},{1005,"SideTradeReportID"},{1006,"SideFillStationCd"},{1007,"SideReasonCd"},{1008,"SideTrdSubTyp"},{1009,"SideLastQty"},{1011,"MessageEventSource"},{1012,"SideTrdRegTimestamp"},{1013,"SideTrdRegTimestampType"},{1014,"SideTrdRegTimestampSrc"},{1015,"AsOfIndicator"},{1016,"NoSideTrdRegTS"},{1017,"LegOptionRatio"},{1018,"NoInstrumentParties"},{1019,"InstrumentPartyID"},{1020,"TradeVolume"},{1021,"MDBookType"},{1022,"MDFeedType"},{1023,"MDPriceLevel"},{1024,"MDOriginType"},{1025,"FirstPx"},{1026,"MDEntrySpotRate"},{1027,"MDEntryForwardPoints"},{1028,"ManualOrderIndicator"},{1029,"CustDirectedOrder"},{1030,"ReceivedDeptID"},{1031,"CustOrderHandlingInst"},{1032,"OrderHandlingInstSource"},{1033,"DeskType"},{1034,"DeskTypeSource"},{1035,"DeskOrderHandlingInst"},{1036,"ExecAckStatus"},{1037,"UnderlyingDeliveryAmount"},{1038,"UnderlyingCapValue"},{1039,"UnderlyingSettlMethod"},{1040,"SecondaryTradeID"},{1041,"FirmTradeID"},{1042,"SecondaryFirmTradeID"},{1043,"CollApplType"},{1044,"UnderlyingAdjustedQuantity"},{1045,"UnderlyingFXRate"},{1046,"UnderlyingFXRateCalc"},{1047,"AllocPositionEffect"},{1048,"DealingCapacity"},{1049,"InstrmtAssignmentMethod"},{1050,"InstrumentPartyIDSource"},{1051,"InstrumentPartyRole"},{1052,"NoInstrumentPartySubIDs"},{1053,"InstrumentPartySubID"},{1054,"InstrumentPartySubIDType"},{1055,"PositionCurrency"},{1056,"CalculatedCcyLastQty"},{1057,"AggressorIndicator"},{1058,"NoUndlyInstrumentParties"},{1059,"UnderlyingInstrumentPartyID"},{1060,"UnderlyingInstrumentPartyIDSource"},{1061,"UnderlyingInstrumentPartyRole"},{1062,"NoUndlyInstrumentPartySubIDs"},{1063,"UnderlyingInstrumentPartySubID"},{1064,"UnderlyingInstrumentPartySubIDType"},{1065,"BidSwapPoints"},{1066,"OfferSwapPoints"},{1067,"LegBidForwardPoints"},{1068,"LegOfferForwardPoints"},{1069,"SwapPoints"},{1070,"MDQuoteType"},{1071,"LastSwapPoints"},{1072,"SideGrossTradeAmt"},{1073,"LegLastForwardPoints"},{1074,"LegCalculatedCcyLastQty"},{1075,"LegGrossTradeAmt"},{1079,"MaturityTime"},{1080,"RefOrderID"},{1081,"RefOrderIDSource"},{1082,"SecondaryDisplayQty"},{1083,"DisplayWhen"},{1084,"DisplayMethod"},{1085,"DisplayLowQty"},{1086,"DisplayHighQty"},{1087,"DisplayMinIncr"},{1088,"RefreshQty"},{1089,"MatchIncrement"},{1090,"MaxPriceLevels"},{1091,"PreTradeAnonymity"},{1092,"PriceProtectionScope"},{1093,"LotType"},{1094,"PegPriceType"},{1095,"PeggedRefPrice"},{1096,"PegSecurityIDSource"},{1097,"PegSecurityID"},{1098,"PegSymbol"},{1099,"PegSecurityDesc"},{1100,"TriggerType"},{1101,"TriggerAction"},{1102,"TriggerPrice"},{1103,"TriggerSymbol"},{1104,"TriggerSecurityID"},{1105,"TriggerSecurityIDSource"},{1106,"TriggerSecurityDesc"},{1107,"TriggerPriceType"},{1108,"TriggerPriceTypeScope"},{1109,"TriggerPriceDirection"},{1110,"TriggerNewPrice"},{1111,"TriggerOrderType"},{1112,"TriggerNewQty"},{1113,"TriggerTradingSessionID"},{1114,"TriggerTradingSessionSubID"},{1115,"OrderCategory"},{1116,"NoRootPartyIDs"},{1117,"RootPartyID"},{1118,"RootPartyIDSource"},{1119,"RootPartyRole"},{1120,"NoRootPartySubIDs"},{1121,"RootPartySubID"},{1122,"RootPartySubIDType"},{1123,"TradeHandlingInstr"},{1124,"OrigTradeHandlingInstr"},{1125,"OrigTradeDate"},{1126,"OrigTradeID"},{1127,"OrigSecondaryTradeID"},{1128,"ApplVerID"},{1129,"CstmApplVerID"},{1130,"RefApplVerID"},{1131,"RefCstmApplVerID"},{1132,"TZTransactTime"},{1133,"ExDestinationIDSource"},{1134,"ReportedPxDiff"},{1135,"RptSys"},{1136,"AllocClearingFeeIndicator"},{1137,"DefaultApplVerID"},{1138,"DisplayQty"},{1139,"ExchangeSpecialInstructions"},{1140,"MaxTradeVol"},{1141,"NoMDFeedTypes"},{1142,"MatchAlgorithm"},{1143,"MaxPriceVariation"},{1144,"ImpliedMarketIndicator"},{1145,"EventTime"},{1146,"MinPriceIncrementAmount"},{1147,"UnitOfMeasureQty"},{1148,"LowLimitPrice"},{1149,"HighLimitPrice"},{1150,"TradingReferencePrice"},{1151,"SecurityGroup"},{1152,"LegNumber"},{1153,"SettlementCycleNo"},{1154,"SideCurrency"},{1155,"SideSettlCurrency"},{1156,"ApplExtID"},{1157,"CcyAmt"},{1158,"NoSettlDetails"},{1159,"SettlObligMode"},{1160,"SettlObligMsgID"},{1161,"SettlObligID"},{1162,"SettlObligTransType"},{1163,"SettlObligRefID"},{1164,"SettlObligSource"},{1165,"NoSettlOblig"},{1166,"QuoteMsgID"},{1167,"QuoteEntryStatus"},{1168,"TotNoCxldQuotes"},{1169,"TotNoAccQuotes"},{1170,"TotNoRejQuotes"},{1171,"PrivateQuote"},{1172,"RespondentType"},{1173,"MDSubBookType"},{1174,"SecurityTradingEvent"},{1175,"NoStatsIndicators"},{1176,"StatsType"},{1177,"NoOfSecSizes"},{1178,"MDSecSizeType"},{1179,"MDSecSize"},{1180,"ApplID"},{1181,"ApplSeqNum"},{1182,"ApplBegSeqNum"},{1183,"ApplEndSeqNum"},{1184,"SecurityXMLLen"},{1185,"SecurityXML"},{1186,"SecurityXMLSchema"},{1187,"RefreshIndicator"},{1188,"Volatility"},{1189,"TimeToExpiration"},{1190,"RiskFreeRate"},{1191,"PriceUnitOfMeasure"},{1192,"PriceUnitOfMeasureQty"},{1193,"SettlMethod"},{1194,"ExerciseStyle"},{1195,"OptPayoutAmount"},{1196,"PriceQuoteMethod"},{1197,"ValuationMethod"},{1198,"ListMethod"},{1199,"CapPrice"},{1200,"FloorPrice"},{1201,"NoStrikeRules"},{1202,"StartStrikePxRange"},{1203,"EndStrikePxRange"},{1204,"StrikeIncrement"},{1205,"NoTickRules"},{1206,"StartTickPriceRange"},{1207,"EndTickPriceRange"},{1208,"TickIncrement"},{1209,"TickRuleType"},{1210,"NestedInstrAttribType"},{1211,"NestedInstrAttribValue"},{1212,"LegMaturityTime"},{1213,"UnderlyingMaturityTime"},{1214,"DerivativeSymbol"},{1215,"DerivativeSymbolSfx"},{1216,"DerivativeSecurityID"},{1217,"DerivativeSecurityIDSource"},{1218,"NoDerivativeSecurityAltID"},{1219,"DerivativeSecurityAltID"},{1220,"DerivativeSecurityAltIDSource"},{1221,"SecondaryLowLimitPrice"},{1222,"MaturityRuleID"},{1223,"StrikeRuleID"},{1224,"LegUnitOfMeasureQty"},{1225,"DerivativeOptPayAmount"},{1226,"EndMaturityMonthYear"},{1227,"ProductComplex"},{1228,"DerivativeProductComplex"},{1229,"MaturityMonthYearIncrement"},{1230,"SecondaryHighLimitPrice"},{1231,"MinLotSize"},{1232,"NoExecInstRules"},{1234,"NoLotTypeRules"},{1235,"NoMatchRules"},{1236,"NoMaturityRules"},{1237,"NoOrdTypeRules"},{1239,"NoTimeInForceRules"},{1240,"SecondaryTradingReferencePrice"},{1241,"StartMaturityMonthYear"},{1242,"FlexProductEligibilityIndicator"},{1243,"DerivFlexProductEligibilityIndicator"},{1244,"FlexibleIndicator"},{1245,"TradingCurrency"},{1246,"DerivativeProduct"},{1247,"DerivativeSecurityGroup"},{1248,"DerivativeCFICode"},{1249,"DerivativeSecurityType"},{1250,"DerivativeSecuritySubType"},{1251,"DerivativeMaturityMonthYear"},{1252,"DerivativeMaturityDate"},{1253,"DerivativeMaturityTime"},{1254,"DerivativeSettleOnOpenFlag"},{1255,"DerivativeInstrmtAssignmentMethod"},{1256,"DerivativeSecurityStatus"},{1257,"DerivativeInstrRegistry"},{1258,"DerivativeCountryOfIssue"},{1259,"DerivativeStateOrProvinceOfIssue"},{1260,"DerivativeLocaleOfIssue"},{1261,"DerivativeStrikePrice"},{1262,"DerivativeStrikeCurrency"},{1263,"DerivativeStrikeMultiplier"},{1264,"DerivativeStrikeValue"},{1265,"DerivativeOptAttribute"},{1266,"DerivativeContractMultiplier"},{1267,"DerivativeMinPriceIncrement"},{1268,"DerivativeMinPriceIncrementAmount"},{1269,"DerivativeUnitOfMeasure"},{1270,"DerivativeUnitOfMeasureQty"},{1271,"DerivativeTimeUnit"},{1272,"DerivativeSecurityExchange"},
    {1273,"DerivativePositionLimit"},{1274,"DerivativeNTPositionLimit"},{1275,"DerivativeIssuer"},{1276,"DerivativeIssueDate"},{1277,"DerivativeEncodedIssuerLen"},{1278,"DerivativeEncodedIssuer"},{1279,"DerivativeSecurityDesc"},{1280,"DerivativeEncodedSecurityDescLen"},{1281,"DerivativeEncodedSecurityDesc"},{1282,"DerivativeSecurityXMLLen"},{1283,"DerivativeSecurityXML"},{1284,"DerivativeSecurityXMLSchema"},{1285,"DerivativeContractSettlMonth"},{1286,"NoDerivativeEvents"},{1287,"DerivativeEventType"},{1288,"DerivativeEventDate"},{1289,"DerivativeEventTime"},{1290,"DerivativeEventPx"},{1291,"DerivativeEventText"},{1292,"NoDerivativeInstrumentParties"},{1293,"DerivativeInstrumentPartyID"},{1294,"DerivativeInstrumentPartyIDSource"},{1295,"DerivativeInstrumentPartyRole"},{1296,"NoDerivativeInstrumentPartySubIDs"},{1297,"DerivativeInstrumentPartySubID"},{1298,"DerivativeInstrumentPartySubIDType"},{1299,"DerivativeExerciseStyle"},{1300,"MarketSegmentID"},{1301,"MarketID"},{1302,"MaturityMonthYearIncrementUnits"},{1303,"MaturityMonthYearFormat"},{1304,"StrikeExerciseStyle"},{1305,"SecondaryPriceLimitType"},{1306,"PriceLimitType"},{1308,"ExecInstValue"},{1309,"NoTradingSessionRules"},{1310,"NoMarketSegments"},{1311,"NoDerivativeInstrAttrib"},{1312,"NoNestedInstrAttrib"},{1313,"DerivativeInstrAttribType"},{1314,"DerivativeInstrAttribValue"},{1315,"DerivativePriceUnitOfMeasure"},{1316,"DerivativePriceUnitOfMeasureQty"},{1317,"DerivativeSettlMethod"},{1318,"DerivativePriceQuoteMethod"},{1319,"DerivativeValuationMethod"},{1320,"DerivativeListMethod"},{1321,"DerivativeCapPrice"},{1322,"DerivativeFloorPrice"},{1323,"DerivativePutOrCall"},{1324,"ListUpdateAction"},{1325,"ParentMktSegmID"},{1326,"TradingSessionDesc"},{1327,"TradSesUpdateAction"},{1328,"RejectText"},{1329,"FeeMultiplier"},{1330,"UnderlyingLegSymbol"},{1331,"UnderlyingLegSymbolSfx"},{1332,"UnderlyingLegSecurityID"},{1333,"UnderlyingLegSecurityIDSource"},{1334,"NoUnderlyingLegSecurityAltID"},{1335,"UnderlyingLegSecurityAltID"},{1336,"UnderlyingLegSecurityAltIDSource"},{1337,"UnderlyingLegSecurityType"},{1338,"UnderlyingLegSecuritySubType"},{1339,"UnderlyingLegMaturityMonthYear"},{1340,"UnderlyingLegStrikePrice"},{1341,"UnderlyingLegSecurityExchange"},{1342,"NoOfLegUnderlyings"},{1343,"UnderlyingLegPutOrCall"},{1344,"UnderlyingLegCFICode"},{1345,"UnderlyingLegMaturityDate"},{1346,"ApplReqID"},{1347,"ApplReqType"},{1348,"ApplResponseType"},{1349,"ApplTotalMessageCount"},{1350,"ApplLastSeqNum"},{1351,"NoApplIDs"},{1352,"ApplResendFlag"},{1353,"ApplResponseID"},{1354,"ApplResponseError"},{1355,"RefApplID"},{1356,"ApplReportID"},{1357,"RefApplLastSeqNum"},{1358,"LegPutOrCall"},{1361,"TotNoFills"},{1362,"NoFills"},{1363,"FillExecID"},{1364,"FillPx"},{1365,"FillQty"},{1366,"LegAllocID"},{1367,"LegAllocSettlCurrency"},{1368,"TradSesEvent"},{1369,"MassActionReportID"},{1370,"NoNotAffectedOrders"},{1371,"NotAffectedOrderID"},{1372,"NotAffOrigClOrdID"},{1373,"MassActionType"},{1374,"MassActionScope"},{1375,"MassActionResponse"},{1376,"MassActionRejectReason"},{1377,"MultilegModel"},{1378,"MultilegPriceMethod"},{1379,"LegVolatility"},{1380,"DividendYield"},{1381,"LegDividendYield"},{1382,"CurrencyRatio"},{1383,"LegCurrencyRatio"},{1384,"LegExecInst"},{1385,"ContingencyType"},{1386,"ListRejectReason"},{1387,"NoTrdRepIndicators"},{1388,"TrdRepPartyRole"},{1389,"TrdRepIndicator"},{1390,"TradePublishIndicator"},{1391,"UnderlyingLegOptAttribute"},{1392,"UnderlyingLegSecurityDesc"},{1393,"MarketReqID"},{1394,"MarketReportID"},{1395,"MarketUpdateAction"},{1396,"MarketSegmentDesc"},{1397,"EncodedMktSegmDescLen"},{1398,"EncodedMktSegmDesc"},{1399,"ApplNewSeqNum"},{1400,"EncryptedPasswordMethod"},{1401,"EncryptedPasswordLen"},{1402,"EncryptedPassword"},{1403,"EncryptedNewPasswordLen"},{1404,"EncryptedNewPassword"},{1405,"UnderlyingLegMaturityTime"},{1406,"RefApplExtID"},{1407,"DefaultApplExtID"},{1408,"DefaultCstmApplVerID"},{1409,"SessionStatus"},{1410,"DefaultVerIndicator"},{1411,"Nested4PartySubIDType"},{1412,"Nested4PartySubID"},{1413,"NoNested4PartySubIDs"},{1414,"NoNested4PartyIDs"},{1415,"Nested4PartyID"},{1416,"Nested4PartyIDSource"},{1417,"Nested4PartyRole"},{1418,"LegLastQty"},{1419,"UnderlyingExerciseStyle"},{1420,"LegExerciseStyle"},{1421,"LegPriceUnitOfMeasure"},{1422,"LegPriceUnitOfMeasureQty"},{1423,"UnderlyingUnitOfMeasureQty"},{1424,"UnderlyingPriceUnitOfMeasure"},{1425,"UnderlyingPriceUnitOfMeasureQty"},{1426,"ApplReportType"},{1427,"SideExecID"},{1428,"OrderDelay"},{1429,"OrderDelayUnit"},{1430,"VenueType"},{1431,"RefOrdIDReason"},{1432,"OrigCustOrderCapacity"},{1433,"RefApplReqID"},{1434,"ModelType"},{1435,"ContractMultiplierUnit"},{1436,"LegContractMultiplierUnit"},{1437,"UnderlyingContractMultiplierUnit"},{1438,"DerivativeContractMultiplierUnit"},{1439,"FlowScheduleType"},{1440,"LegFlowScheduleType"},{1441,"UnderlyingFlowScheduleType"},{1442,"DerivativeFlowScheduleType"},{1443,"FillLiquidityInd"},{1444,"SideLiquidityInd"},{1445,"NoRateSources"},{1446,"RateSource"},{1447,"RateSourceType"},{1448,"ReferencePage"},{1449,"RestructuringType"},{1450,"Seniority"},{1451,"NotionalPercentageOutstanding"},{1452,"OriginalNotionalPercentageOutstanding"},{1453,"UnderlyingRestructuringType"},{1454,"UnderlyingSeniority"},{1455,"UnderlyingNotionalPercentageOutstanding"},{1456,"UnderlyingOriginalNotionalPercentageOutstanding"},{1457,"AttachmentPoint"},{1458,"DetachmentPoint"},{1459,"UnderlyingAttachmentPoint"},{1460,"UnderlyingDetachmentPoint"},{1461,"NoTargetPartyIDs"},{1462,"TargetPartyID"},{1463,"TargetPartyIDSource"},{1464,"TargetPartyRole"},{1465,"SecurityListID"},{1466,"SecurityListRefID"},{1467,"SecurityListDesc"},{1468,"EncodedSecurityListDescLen"},{1469,"EncodedSecurityListDesc"},{1470,"SecurityListType"},{1471,"SecurityListTypeSource"},{1472,"NewsID"},{1473,"NewsCategory"},{1474,"LanguageCode"},{1475,"NoNewsRefIDs"},{1476,"NewsRefID"},{1477,"NewsRefType"},{1478,"StrikePriceDeterminationMethod"},{1479,"StrikePriceBoundaryMethod"},{1480,"StrikePriceBoundaryPrecision"},{1481,"UnderlyingPriceDeterminationMethod"},{1482,"OptPayoutType"},{1483,"NoComplexEvents"},{1484,"ComplexEventType"},{1485,"ComplexOptPayoutAmount"},{1486,"ComplexEventPrice"},{1487,"ComplexEventPriceBoundaryMethod"},{1488,"ComplexEventPriceBoundaryPrecision"},{1489,"ComplexEventPriceTimeType"},{1490,"ComplexEventCondition"},{1491,"NoComplexEventDates"},{1492,"ComplexEventStartDate"},{1493,"ComplexEventEndDate"},{1494,"NoComplexEventTimes"},{1495,"ComplexEventStartTime"},{1496,"ComplexEventEndTime"},{1497,"StreamAsgnReqID"},{1498,"StreamAsgnReqType"},{1499,"NoAsgnReqs"},{1500,"MDStreamID"},{1501,"StreamAsgnRptID"},{1502,"StreamAsgnRejReason"},{1503,"StreamAsgnAckType"},{1504,"RelSymTransactTime"},{1617,"StreamAsgnType"}};
    string::size_type pos = 0;
    int count_character = 0;
    int count_num = 0;
    // 第一次统计总需要字符串大小, 避免误会，最后一个字符不'|'不纳入统计范围，同时开头8也不纳入修改范围。
    while(pos < (my_str.size() - 1)){
        if('|' == my_str[pos]){
            count_num++;
            int j = pos;
            while('=' != my_str[j]){
                j++;
            }
            count_character += map_for_fix_code[atoi(my_str.substr(pos+1, j).c_str())].size();
        }
        ++pos;
    }
    // 临时字符串，用于存储返回结果
    string temp_str;
    temp_str.resize(count_character + my_str.size() + count_num*2); // 多出来的字符串 + 本身字符串长度 + 括号
    pos = 0;
    int new_pos = 0; // 用于单次复制
    while(pos < (my_str.size() - 1)){ // 最后一个字符的'|'不需要考虑
        temp_str[new_pos] = my_str[pos];
        if('|' == my_str[pos]){
            int j = pos;
            while('=' != my_str[j]){
                j++;
            }
            string temp_str_str = map_for_fix_code[atoi(my_str.substr(pos+1, j).c_str())];
            int len = temp_str_str.size();
            // 进行代码-->特定字符
            for(int k=0; k<len; k++)
            {
                temp_str[++new_pos] = temp_str_str[k];            
            }
            // 加上括号
            temp_str[++new_pos] = '(';
            for(int k=pos+1; k<j; k++)          {
                temp_str[++new_pos] = my_str[k];
            }
            temp_str[++new_pos] = ')';
            pos = j-1; // 所有的数字拷贝完了。
        }
        ++pos;
        ++new_pos;
    }
    temp_str[new_pos] = my_str[my_str.size()-1];
    cout << temp_str;
}